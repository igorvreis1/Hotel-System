mkdir compile
xcopy C:\Users\Coruja\Desktop\Hotel-System\Arquivos\Dados\*.* C:\Users\Coruja\Desktop\Hotel-System\Arquivos\compile /y
xcopy C:\Users\Coruja\Desktop\Hotel-System\Arquivos\Standart\*.* C:\Users\Coruja\Desktop\Hotel-System\Arquivos\compile /y

cd compile
gcc -c dados.c main.c functions.c
gcc main.o dados.o functions.o -o main.exe
pause

xcopy C:\Users\Coruja\Desktop\Hotel-System\Arquivos\compile\main.exe c:\users\Coruja\Desktop\Hotel-System\Arquivos /y
rmdir C:\User\Coruja\Desktop\Hotel-System\Arquivos\compile /y