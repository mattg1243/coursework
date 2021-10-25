import pandas as pd
import calendar


def date_to_day(row):
    return calendar.day_name[row.weekday()]


fn = "c19_timeseries.csv"
weekdays = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
weekend = ['Saturday', 'Sunday']

frame = pd.read_csv(fn, usecols=['date', 'area', 'cases'], parse_dates=['date'])


al = frame[frame['area'] == 'Yolo'].copy()

al['cases'] = al['cases'].astype(int)
al['dayOfWeek'] = al['date'].apply(date_to_day)

print(al.head())

finalFrame = al.groupby('dayOfWeek').sum().sort_values(by='cases', ascending=False).reset_index()

print(finalFrame.head(7))

""" 
    What day of the week had the highest number of cases, and what was the count?  (Monday, Tuesday, etc.)
    What day of the week had the lowest number of case counts, and what was the count?
    Was the average of new cases higher on weekends or on weekdays?
"""

highestDay = {'day': finalFrame['dayOfWeek'][0],
              'cases': finalFrame['cases'][0]}
lowestDay = {'day': finalFrame['dayOfWeek'][6],
             'cases': finalFrame['cases'][6]}

weekdaysDf = finalFrame.loc[finalFrame['dayOfWeek'].isin(weekdays), 'cases']
weekendDf = finalFrame.loc[finalFrame['dayOfWeek'].isin(weekend), 'cases']

print(f'The day with the highest number of cases reported was {highestDay["day"]} with {highestDay["cases"]} cases. '
      f'The day with the lowest number of cases reported was {lowestDay["day"]} with {lowestDay["cases"]} cases. ')

if weekdaysDf.mean() > weekendDf.mean():
    print('The average number of cases was higher on weekdays')
else:
    print('The average number of cases was higher on weekends')