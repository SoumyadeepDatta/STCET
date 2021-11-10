trap "kill 0" EXIT

./someProcessA &
./someProcessB &

ps -a
