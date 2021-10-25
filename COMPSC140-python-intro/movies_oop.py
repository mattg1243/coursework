import random


class Movie:

    def __init__(self, title, releaseYear, director, genre, length, rating):
        self.title = title
        self.releaseYear = releaseYear
        self.director = director
        self.genre = genre
        self.length = length
        self.rating = rating

    def __str__(self):
        return f'{self.title} ({", ".join(self.genre)}, {self.releaseYear}) directed by {self.director}, ' \
               f'length {self.length} minutes, rated {self.rating}.'


#   did this so as to not initialize new objects in the dictionary but this is also kind of messy...
Apollo13 = Movie('Apollo 13', 1995, 'Ron Howard', ['drama', 'adventure'], 140, 'PG')
Terminator = Movie('Terminator', 1984, 'James Cameron', ['action', 'sci-fi'], 107, 'R')
TheLionKing = Movie('The Lion King', 1994, 'Rob Minkoff', ['family', 'musical'], 89, 'G')
Titanic = Movie('Titanic', 1997, 'James Cameron', ['romance', 'drama'], 210, 'PG-13')
TheWizardOfOz = Movie('The Wizard of Oz', 1939, 'Victor Fleming', ['fantasy', 'musical'], 118, 'G')
StarWars = Movie('Star Wars', 1977, 'George Lucas', ['sci-fi', 'adventure'], 125, 'PG')
DirtyHarry = Movie('Dirty Harry', 1971, 'Don Siegel', ['action', 'thriller'], 103, 'R')
ForrestGump = Movie('Forrest Gump', 1994, 'Robert Zemeckis', ['drama', 'romance'], 142, 'PG-13')
Frankenstein = Movie('Frankenstein', 1931, 'James Whale', ['horror', 'sci-fi'], 71, 'PG-13')
FindingNemo = Movie('Finding Nemo', 2003, 'Andrew Stanton', ['family', 'adventure'], 100, 'G')

quotes = {"Houston, we have a problem": Apollo13,
          "I'll be back": Terminator,
          "Remember who you are": TheLionKing,
          "I'm the king of the world": Titanic,
          "There's no place like home": TheWizardOfOz,
          "May the Force be with you": StarWars,
          "Go ahead, make my day": DirtyHarry,
          "My mama always said life is like a box of chocolates": ForrestGump,
          "It's alive! It's alive!": Frankenstein,
          "Just keep swimming": FindingNemo
          }

questions_amount = int(input(f"Welcome to the Movie Quotes Quiz Game! How many questions "
                             f"would you like to attempt? (up to {len(list(quotes))}) "))

while questions_amount > len(list(quotes)):
    questions_amount = int(input(f"Error: please enter the number of questions you would like to attempt "
                                 f"up to {len(list(quotes))} "))

rset = random.sample(list(quotes), questions_amount)

score = 0
counter = 1

for i in rset:
    answer = quotes[f'{i}']
    guess = input(f'Question #{counter} - What movie is this quote from? : \n\t\t"{i}"\n')
    if guess.lower() == answer.title.lower():
        print("Good job, that's correct!")
        score += 1
    else:
        print(f"Sorry, the correct answer was {answer.__str__()}")

    counter += 1

    print('---------------------------------')

print(f"\nYou finished with a total score of {score} out of {questions_amount}")
