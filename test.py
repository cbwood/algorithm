import pandas as pd
import datetime, random


def randomtimes(start, end, n, frmt="%Y-%m-%d %H:%M:%S"):
    stime = datetime.datetime.strptime(start, frmt)
    etime = datetime.datetime.strptime(end, frmt)
    return [(random.random() * (etime - stime) + stime).strftime('%H:%M:%S') for _ in range(n)]


if __name__ == '__main__':
    li = []
    # for i in range(30):
    #     li.append()
    # print(randomDateList('08:20:00', '08:50:00', 10))
    li.append(randomtimes('2021-01-01 08:20:00', '2021-01-01 08:50:00', 30))
    li.append(randomtimes('2021-01-01 18:20:00', '2021-01-01 19:50:00', 30))
    li.append(randomtimes('2021-01-01 08:20:00', '2021-01-01 08:50:00', 30))
    li.append(randomtimes('2021-01-01 18:20:00', '2021-01-01 19:50:00', 30))
    li.append(randomtimes('2021-01-01 08:20:00', '2021-01-01 08:50:00', 30))
    li.append(randomtimes('2021-01-01 18:20:00', '2021-01-01 19:50:00', 30))
    li.append(randomtimes('2021-01-01 08:20:00', '2021-01-01 08:50:00', 30))
    li.append(randomtimes('2021-01-01 18:20:00', '2021-01-01 18:50:00', 30))
    li.append(randomtimes('2021-01-01 08:20:00', '2021-01-01 08:50:00', 30))
    li.append(randomtimes('2021-01-01 18:20:00', '2021-01-01 18:50:00', 30))
    dt = pd.DataFrame(li)
    dt.to_excel("new.xlsx")

