@echo off
echo 即将删除以下.exe文件:
@REM 找.exe和tempCodeRunnerFile.cpp
for /r %%i in (*.exe tempCodeRunnerFile.cpp) do (
  echo 找到: %%i
)

echo.
set /p confirm=是否继续删除这些文件? (Y/N):
if /i "%confirm%"=="Y" (
  for /r %%i in (*.exe tempCodeRunnerFile.cpp) do (
    echo 删除: %%i
    del "%%i"
  )
  echo 删除完成。
) else (
  echo 已取消删除操作。
)
