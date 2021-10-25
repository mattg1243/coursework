import random

quotes_dict = {"Houston, we have a problem": "Apollo 13",
               "I'll be back": "Terminator",
               "Remember who you are": "The Lion King",
               "I'm the king of the world": "Titanic",
               "There's no place like home": "The Wizard of Oz",
               "May the Force be with you": "Star Wars",
               "Go ahead, make my day": "Dirty Harry",
               "My mama always said life is like a box of chocolates": "Forrest Gump",
               "It's alive! It's alive!": "Frankenstein",
               "Just keep swimming": "Finding Nemo"
               }

questions_amount = int(input(f"Welcome to the Movie Quotes Quiz Game! How many questions "
                             f"would you like to attempt? (up to {len(quotes_dict)}) "))
# if questions_amount > len(quotes_dict):
while questions_amount > len(quotes_dict):
    questions_amount = int(input(f"Error: please enter the number of questions you would like to attempt "
                                 f"up to {len(quotes_dict)} "))

rset = random.sample(list(quotes_dict), questions_amount)

score = 0
counter = 0

for i in rset:
    answer = quotes_dict[f'{i}']
    guess = input(f'Question #{counter + 1} - What movie is this quote from? : \n\t\t"{i}"\n')
    if guess.lower() == answer.lower():
        print("Good job, that's correct!")
        score += 1
    else:
        print(f"Sorry, the correct answer was '{answer}'")

    counter += 1
    if counter == questions_amount:
        break

    print('---------------------------------')

print(f"\nYou finished with a total score of {score} out of {questions_amount}")