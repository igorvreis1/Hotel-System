mkdir compile

xcopy C:\Users\igorv\Desktop\Hotel-System\Arquivos\reservas\*.* C:\Users\igorv\Desktop\Hotel-System\Arquivos\compile /y
xcopy C:\Users\igorv\Desktop\Hotel-System\Arquivos\Dados\*.* C:\Users\igorv\Desktop\Hotel-System\Arquivos\compile /y

cd compile
gcc -c reserva.c main.c dados.c
gcc main.o reserva.o dados.o -o main.exe
pause

xcopy C:\Users\igorv\Desktop\Hotel-System\Arquivos\compile\main.exe C:\Users\igorv\Desktop\Hotel-System\Arquivos /y
rmdir C:\Users\igorv\Desktop\Hotel-System\Arquivos\compile /y