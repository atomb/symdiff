REM Usage update_symdiff_components <PATH-TO-SYMDIFF-SHAREPOINT-DISTRIBUTION>

set SYMDIFF_DISTR_ROOT=%1

call xcopy /S /Y %SYMDIFF_DISTR_ROOT%\scripts\cygwin_binaries\* %SYMDIFF_ROOT%\scripts\cygwin_binaries\

call xcopy /S /Y %SYMDIFF_DISTR_ROOT%\havoc_dlls\* %SYMDIFF_ROOT%\havoc_dlls\
