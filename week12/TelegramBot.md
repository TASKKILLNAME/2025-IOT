async def dustToInfluxDB(context: ContextTypes.DEFAULT_TYPE) -> None:
    if seri.in_waiting !=0:
        content = seri.readline()
        a = float(content.decode())
        job = context.job
        await context.bot.send_message(job.chat_id, text=f"Dust Sensor Value! {a}")

# Handler 등록
application.add_handler(CommandHandler("dust", dustToInfluxDB))
application.add_handler(CommandHandler("set", set_timer))

# 타이머 설정
context.job_queue.run_repeating(dustToInfluxDB, due, chat_id=chat_id, name=str(chat_id), data=due)
