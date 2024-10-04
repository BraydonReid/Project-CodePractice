
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# Try opening the file with a different encoding
with open("encrypt.txt", "r", encoding="ISO-8859-1") as file:
    file_content = file.read()

# Sender and receiver information
sender = "Braydon Reid <hello@demomailtrap.com>"
receiver = "Whom it concerns <DawsonReid04@gmail.com>"

# Creating the email message
message = MIMEMultipart()
message["Subject"] = "Encrypted Message Try to Decrypt It!"
message["From"] = sender
message["To"] = receiver

# Attach the file content as the email body
message.attach(MIMEText(file_content, "plain", "utf-8"))

# Send the email using Mailtrap's SMTP server
with smtplib.SMTP("live.smtp.mailtrap.io", 587) as server:
    server.starttls()
    server.login("api", "91e76a892458ac665440883dad067cb7")
    server.sendmail(sender, receiver, message.as_string())

print("Email sent successfully!")
