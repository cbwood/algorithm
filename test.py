from datetime import datetime
import requests


def send_wechat(title, content):
    # title and content must be string.
    sckey = "SCT46659TW1J3uGyrf9soYdluC9Fmrl4r"  # your key
    url = 'https://sctapi.ftqq.com/' + sckey + '.send'
    data = {'text': title, 'desp': content}
    result = requests.post(url, data)


if __name__ == '__main__':
    now = datetime(2021, 6, 19, 8, 30)
    start = datetime(2021, 6, 19, 1)
    # send_wechat("bigevent", str(now-start))
    print(str(now - start))
