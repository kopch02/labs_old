import telebot
bot=telebot.TeleBot('5271255680:AAFhXPKPLl5iKZWezqwc-aICJIeY2CVlKzI')
@bot.message_handler(commands=['start','help'])
def sand_welcome(message):
    bot.reply_to(message,f'я ботяра очередняра')
def get_text_message(message):
    if message.text.lower()=="привет":
        bot.send_message(message,f"ну привет")
    else:
        bot.send_message(message.from_user.id,"i don't understude")
        
bot.polling()