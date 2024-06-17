# Projekt-Gra-rpg
Jest to gra w której sterujemy bohaterem przemieszczającym się po losowym lochu, pokonując potwory i rosnąc w siłę.

Do stworzenia gry użyłem programu Clion oraz 32 bitowej wersji SFMLa (2.5.1). Do zagrania w grę będą nam potrzebne te programy. Posiadając wspomniane wcześniej aplikacje, należy do nowego folderu wrzucić pobrane pliki z tego repozytorium, a następnie zmienić: 
# -set(SFML_DIR "C:/Users/piotr/OneDrive/Pulpit/projekt/SFML-2.5.1//lib/cmake/SFML"), w Cmake na ścieżkę do pobranego wcześniej SFMLa. 
# -if (!font.loadFromFile("C:\\Users\\piotr\\OneDrive\\Pulpit\\projekt\\arial.ttf")) w kodzie na ścieżkę do pobranego pliku arial.ttf. 
Do pewnego działania gry wymagane jest pobranie plików dodatkowych, z folderu o tej samej nazwie, a następnie umieszczenie ich w folderze z grą.

Po skompilowaniu głównego pliku naszym oczą ukaże sie plansza po której można poruszać się naszym bohaterem za pomocą strzałek. Celem gry jest zdobywanie poziomów, zwiększanie statystyk podczas walki z wrogami aby zajść jak najdalej. Wychodząc poza mapę odnawia nam się życie ale przeciwnicy też stają się trudniejsi, dlatego lepiej się zastanowić czy to na pewno dobra pora aby przejść na kolejny poziom.


