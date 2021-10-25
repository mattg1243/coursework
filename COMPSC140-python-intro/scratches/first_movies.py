class Movie:

    def __init__(self, title, genre, length, release_year, famous_quotes):
        ''' self.title = title
        self.genre = genre
        self.length = length
        self.release_year = release_year
        self.famous_quotes = [famous_quotes] '''

    def __str__(self):
        movie_str = f'Title : {self.title}\n' \
                    f'Genre : {self.genre}\n' \
                    f'Length : {self.length}\n' \
                    f'Release Year : {self.release_year}\n' \
                    f'Famous Quotes : {self.famous_quotes}\n'
        return movie_str

    def get_title(self):
        return self.title

    def get_genre(self):
        return self.genre

    def get_length(self):
        return self.length

    def get_release_year(self):
        return self.release_year

    def det_famous_quotes(self):
        return self.famous_quotes

    def set_title(self, title):
        self.title = title

    def set_genre(self, genre):
        self.genre = genre

    def set_length(self, length):
        self.length = length

    def set_release_year(self, release_year):
        self.release_year = release_year

    def set_famous_quotes(self, quote_to_add):
        self.famous_quotes.append(quote_to_add)


BigDaddy = Movie('Big Daddy', 'comedy', '1:34:42', '1999', 'I wipe my own ass')

BigDaddy.set_famous_quotes('He taught me to pee on the building')

print(BigDaddy)
