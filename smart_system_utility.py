import os
import shutil
import subprocess
import time

def organize_downloads():
    print("\n[기능 1] 다운로드 폴더 자동 정리")
    downloads_dir = os.path.expanduser('~/Downloads')
    
    if not os.path.exists(downloads_dir):
        print(" - 다운로드 폴더를 찾을 수 없습니다.")
        return

    categories = {
        '사진': ['.jpg', '.png'],
        '문서': ['.pdf', '.hwp', '.docx'],
        '영상': ['.mp4'],
        '코드': ['.py', '.html']
    }
    
    for category in categories.keys():
        category_path = os.path.join(downloads_dir, category)
        if not os.path.exists(category_path):
            os.makedirs(category_path)
            
    moved_count = 0
    for filename in os.listdir(downloads_dir):
        file_path = os.path.join(downloads_dir, filename)
        if os.path.isfile(file_path):
            file_ext = os.path.splitext(filename)[1].lower()
            for category, extensions in categories.items():
                if file_ext in extensions:
                    dest_folder = os.path.join(downloads_dir, category)
                    dest_path = os.path.join(dest_folder, filename)
                    try:
                        shutil.move(file_path, dest_path)
                        moved_count += 1
                    except Exception as e:
                        print(f" - 오류 ({filename}): {e}")
                    break
    print(f" - 총 {moved_count}개의 파일을 정리했습니다.\n")

def batch_change_ext():
    print("\n[기능 2] 확장자 일괄 변경")
    folder_path = input(" - 대상 폴더 절대경로를 입력하세요 (예: C:\\...\\Desktop) : ")
    if not os.path.isdir(folder_path):
        print(" - 유효하지 않은 폴더 경로입니다.\n")
        return
        
    old_ext = input(" - 변경할 기존 확장자를 입력하세요 (예: txt) : ").strip('.').lower()
    new_ext = input(" - 변경될 새로운 확장자를 입력하세요 (예: md) : ").strip('.').lower()
    
    count = 0
    for filename in os.listdir(folder_path):
        if filename.lower().endswith(f".{old_ext}"):
            base_name = os.path.splitext(filename)[0]
            old_path = os.path.join(folder_path, filename)
            new_path = os.path.join(folder_path, f"{base_name}.{new_ext}")
            try:
                os.rename(old_path, new_path)
                count += 1
            except Exception as e:
                print(f" - 오류 ({filename}): {e}")
    print(f" - 총 {count}개의 파일에서 확장자가 [{old_ext}]에서 [{new_ext}](으)로 변경되었습니다.\n")

def list_installed_programs():
    print("\n[기능 3] 설치된 프로그램 조회 (레지스트리 기반)")
    print(" - 정보를 불러오는 중입니다...\n")
    import winreg
    paths = [
        r"SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall",
        r"SOFTWARE\WOW6432Node\Microsoft\Windows\CurrentVersion\Uninstall"
    ]
    programs = []
    
    for path in paths:
        try:
            key = winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE, path)
            for i in range(0, winreg.QueryInfoKey(key)[0]):
                try:
                    skey_name = winreg.EnumKey(key, i)
                    skey = winreg.OpenKey(key, skey_name)
                    name = winreg.QueryValueEx(skey, "DisplayName")[0]
                    if name not in programs:
                        programs.append(name)
                except OSError:
                    pass
        except OSError:
            pass
            
    programs.sort()
    for idx, p in enumerate(programs[:100], 1): # 글 축약을 위해 100개까지만 표시
        print(f" {idx}. {p}")
        
    if len(programs) > 100:
        print(f" ...(외 {len(programs)-100}개의 프로그램 추가로 존재)")
    print()

def list_running_processes():
    print("\n[기능 4] 실행중인 프로세스 목록 (메모리 점유율 상위 20개)")
    if os.name == 'nt':
        try:
            cmd = "powershell -Command \"Get-Process | Sort-Object WorkingSet -Descending | Select-Object -First 20 ProcessName, @{Name='Memory(MB)';Expression={[math]::Round($_.WorkingSet / 1MB, 2)}}\""
            output = subprocess.check_output(cmd, text=True, shell=True)
            print(output)
        except Exception as e:
            print(f" - 프로세스 목록 조회 오류: {e}\n")
    else:
        print(" - 윈도우 환경에서만 지원됩니다.\n")
        
def protect_office_file():
    print("\n[기능 5] Office Word 문서(.docx) 파일 비밀번호 부여")
    print(" *주의: MS Word가 설치되어 있어야 하며 pywin32 라이브러리가 필요합니다.")
    try:
        import win32com.client
    except ImportError:
        print(" - pywin32 모듈이 설치되어 있지 않습니다!")
        print(" - 터미널에서 'pip install pywin32'를 입력해 설치 후 다시 실행해주세요.\n")
        return
        
    file_path = input(" - 암호를 설정할 Word 파일의 절대경로를 입력하세요 (.docx): ")
    if not os.path.isfile(file_path):
        print(" - 파일을 찾을 수 없습니다.\n")
        return
        
    password = input(" - 이 문서에 걸어둘 비밀번호를 입력하세요: ")
    
    try:
        print(" - 암호화 작업을 시작합니다. 잠시만 기다려주세요...")
        word = win32com.client.Dispatch("Word.Application")
        word.Visible = False
        doc = word.Documents.Open(os.path.abspath(file_path))
        
        output_path = file_path.replace(".docx", "_protected.docx")
        
        # 16 = wdFormatDocumentDefault
        doc.SaveAs2(os.path.abspath(output_path), 16, False, password)
        doc.Close()
        word.Quit()
        print(f" - [성공] 암호가 성공적으로 부여된 파일 생성됨:\n   -> {output_path}\n")
    except Exception as e:
        print(f" - 오류가 발생했습니다: {e}\n")
        try:
            word.Quit()
        except:
            pass

def main():
    while True:
        print("="*60)
        print(" 🛠️  강력한 만능 시스템 유틸리티 도구 (By AI)")
        print("="*60)
        print(" 1. 다운로드 폴더 자동 연계 정리")
        print(" 2. 특정 폴더 내 확장자 일괄 변경 (예: txt -> md)")
        print(" 3. 내 컴퓨터에 설치된 프로그램 목록 출력")
        print(" 4. 현재 실행중인 메모리 상위 프로세스 확인")
        print(" 5. Office 특정 파일(Word)에 비밀번호 부여")
        print(" 0. 프로그램 완전 종료")
        print("="*60)
        
        choice = input(" 원하는 기능의 번호를 입력하세요: ")
        
        if choice == '1':
            organize_downloads()
        elif choice == '2':
            batch_change_ext()
        elif choice == '3':
            list_installed_programs()
        elif choice == '4':
            list_running_processes()
        elif choice == '5':
            protect_office_file()
        elif choice == '0':
            print("\n프로그램을 종료합니다. 유용하게 사용하시길 바랍니다!")
            break
        else:
            print("\n잘못된 입력입니다. 메뉴의 번호를 다시 확인해주세요.\n")

if __name__ == "__main__":
    main()
