import pandas as pd
import calendar


def date_to_day(row):
    return calendar.day_name[row.weekday()]


fn = "c19_timeseries.csv"
weekdays = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
weekend = ['Saturday', 'Sunday']

frame = pd.read_csv(fn, usecols=['date', 'area', 'cases'], parse_dates=['date'])

cc = frame[frame['area'] == 'Contra Costa'].copy()
cc['cases'] = cc['cases'].astype(int)
cc['dayOfWeek'] = cc['date'].apply(date_to_day)

finalFrame = cc.groupby('dayOfWeek').sum().sort_values(by='cases', ascending=False).reset_index()

# print(finalFrame.head(7))

highestDay = {'day': finalFrame['dayOfWeek'][0],
              'cases': finalFrame['cases'][0]}
lowestDay = {'day': finalFrame['dayOfWeek'][6],
             'cases': finalFrame['cases'][6]}

weekdaysDf = finalFrame.loc[finalFrame['dayOfWeek'].isin(weekdays), 'cases']
weekendDf = finalFrame.loc[finalFrame['dayOfWeek'].isin(weekend), 'cases']

print(f'\nThe day with the highest number of cases reported was {highestDay["day"]} with {highestDay["cases"]} cases.\n'
      f'The day with the lowest number of cases reported was {lowestDay["day"]} with {lowestDay["cases"]} cases.')

if weekdaysDf.mean() > weekendDf.mean():
    print('The average number of cases was higher on weekdays.')
else:
    print('The average number of cases was higher on weekends.')