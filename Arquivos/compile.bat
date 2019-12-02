mkdir compile
<<<<<<< HEAD

xcopy C:\Users\igorv\Desktop\Hotel-System\Arquivos\reservas\*.* C:\Users\igorv\Desktop\Hotel-System\Arquivos\compile /y
xcopy C:\Users\igorv\Desktop\Hotel-System\Arquivos\Dados\*.* C:\Users\igorv\Desktop\Hotel-System\Arquivos\compile /y

cd compile
gcc -c reserva.c main.c dados.c
gcc main.o reserva.o dados.o -o main.exe
pause

xcopy C:\Users\igorv\Desktop\Hotel-System\Arquivos\compile\main.exe C:\Users\igorv\Desktop\Hotel-System\Arquivos /y
rmdir C:\Users\igorv\Desktop\Hotel-System\Arquivos\compile /y
=======
xcopy /y C:\Users\Coruja\Desktop\Hotel-System\Arquivos\Dados\*.* C:\Users\Coruja\Desktop\Hotel-System\Arquivos\compile
xcopy /y C:\Users\Coruja\Desktop\Hotel-System\Arquivos\Standart\*.* C:\Users\Coruja\Desktop\Hotel-System\Arquivos\compile
xcopy /y C:\Users\Coruja\Desktop\Hotel-System\Arquivos\Visual\*.* C:\Users\Coruja\Desktop\Hotel-System\Arquivos\Compile

cd compile
gcc -c dados.c main.c functions.c usuario.c
gcc main.o dados.o functions.o usuario.o -o main.exe
pause

xcopy /y C:\Users\Coruja\Desktop\Hotel-System\Arquivos\compile\main.exe c:\users\Coruja\Desktop\Hotel-System\Arquivos
erase C:\User\Coruja\Desktop\Hotel-System\Arquivos\compile\*.*
rmdir /y C:\User\Coruja\Desktop\Hotel-System\Arquivos\compile
>>>>>>> upstream/master
