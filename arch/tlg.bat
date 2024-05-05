@echo off

REM Токен вашего бота
set BOT_TOKEN=6039556608:AAEmFO2ovNoP1mIjuyPnwZC_sOd5ld_6Ytw

REM Текст сообщения
set MESSAGE=Kydaxter work

REM Отправляем запрос на Telegram API для получения списка активных диалогов
powershell -Command "& { $response = Invoke-WebRequest -Uri 'https://api.telegram.org/bot%BOT_TOKEN%/getUpdates'; $json = $response.Content | ConvertFrom-Json; foreach ($result in $json.result) { $chat_id = $result.message.chat.id; if ($chat_id) { Invoke-WebRequest -Uri 'https://api.telegram.org/bot%BOT_TOKEN%/sendMessage' -Method Post -Body @{ chat_id = $chat_id; text = '%MESSAGE%'} } } }"
