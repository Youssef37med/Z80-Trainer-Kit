cd C:\Users\LENOVO\Desktop\asymbly\Z80 Trainer Kit Source Code
sdasz80 -o StartUpCode.rel .\StartUpCode.asm
sdcc -mz80 --code-loc 0x90 --data-loc 0x8000 --no-std-crt0 StartUpCode.rel .\main.c
sdobjcopy -I ihex -O binary main.ihx main.bin
pause
$sdcc -mz80 --code-loc 0x100 --data-loc 0x8000 --no-std-crt0 StartUpCode.rel z80.c