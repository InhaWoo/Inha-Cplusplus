#include <iostream>

using namespace std;

class Movie {
private:
	string rating;

public:
	string title;
	string director;
	Movie(string aTitle, string aDirector, string aRating) {
		title = aTitle;
		director = aDirector;
		
		setRating(aRating); //이건 생긴건 함순데 결국 """rating = 무엇무엇""" 이라는 명령어랑 똑같다. void인 이유는 어차피 뭔가를 반환할 필요도 없고,
							//단순히 """rating"""이라는거에 """"무엇무엇"""을 대입하기만 하면 되기 때문.

	}
	void setRating(string aRating) {
		if (aRating == "G" || aRating == "PG" ||
			aRating == "PG-13" || aRating == "R" ||
			aRating == "NR") {
			rating = aRating;
		}
		else {
			rating = "That's invalid Rating.";
		}

	}


	string getRating() {
		return rating;
	}
};


int main()
{
	Movie avengers("The Avengers", "Joss Whedon", "PG-13");

	avengers.setRating("Dog");

	cout << avengers.getRating();


	return 0;
}