# Player-Stats
Identifies the most valuable player in a basketball league.

This program takes in a file as an input where each entry is 3 lines long. The first line is the name of a player(string), the second line is total points (float) and total assists(float) separated by a space. The third line is total minutes the player plays in one season. The last line of the file is the strong "DONE".

The output is a line for each player separated by a space with his DOC. DOC = (points+assists)/minutes. The output is in descending order of DOC. Players with equal DOC are sorted alphabetically. 