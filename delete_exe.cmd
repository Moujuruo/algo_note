@echo off
echo ����ɾ������.exe�ļ�:
@REM ��.exe��tempCodeRunnerFile.cpp
for /r %%i in (*.exe tempCodeRunnerFile.cpp) do (
  echo �ҵ�: %%i
)

echo.
set /p confirm=�Ƿ����ɾ����Щ�ļ�? (Y/N):
if /i "%confirm%"=="Y" (
  for /r %%i in (*.exe tempCodeRunnerFile.cpp) do (
    echo ɾ��: %%i
    del "%%i"
  )
  echo ɾ����ɡ�
) else (
  echo ��ȡ��ɾ��������
)
