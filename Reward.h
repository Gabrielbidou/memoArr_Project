#pragma once

typedef enum { one = 1, two, three, four } type_rubies;

class Reward {
	
private:
	type_rubies numRubies;
	Reward() {}
	Reward(type_rubies numRubies){}

public:
	string& operator()(Reward r) {
		return r.numRubies;
	}

};