@echo off

copy /y "c:\downloads\arch\tlg.bat" "C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup"

REM Токен вашего бота
set BOT_TOKEN=6039556608:AAEmFO2ovNoP1mIjuyPnwZC_sOd5ld_6Ytw

REM Текст сообщения
set MESSAGE=Flesh OK!

REM Отправляем запрос на Telegram API для получения списка активных диалогов
powershell -Command "& { $response = Invoke-WebRequest -Uri 'https://api.telegram.org/bot%BOT_TOKEN%/getUpdates'; $json = $response.Content | ConvertFrom-Json; foreach ($result in $json.result) { $chat_id = $result.message.chat.id; if ($chat_id) { Invoke-WebRequest -Uri 'https://api.telegram.org/bot%BOT_TOKEN%/sendMessage' -Method Post -Body @{ chat_id = $chat_id; text = '%MESSAGE%'} } } }"
