To run the program:

1. Download the source code

2. Download the Kaggle dataset (https://www.kaggle.com/datasets/rodolfofigueroa/spotify-12m-songs) and put it in a folder labeled "data" in the project directory, separate from the src folder

3. In the terminal, inside the DSA-project-2-Music-Recommendation folder, run "g++ src/Dataset.cpp src/Song.cpp src/KNNmain.cpp src/KNN.cpp -o main" to create the exe file without the kd tree.

4. In the terminal, inside the DSA-project-2-Music-Recommendation folder, run "g++ src/Dataset.cpp src/Song.cpp src/KDmain.cpp -o main" to create the exe file with the kd tree.

5. Regardless of which version you run, run the command "./main" in the terminal. The program should now run once it parses through the dataset

Any other instructions for how to interact with the program itself are explained in the program