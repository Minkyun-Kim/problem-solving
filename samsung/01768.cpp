#define N 4

typedef struct {
	int strike;
	int ball;
} Result;


// API
extern Result query(int guess[]);

bool isValid[9877];
int number[5040];
int idx = 0;

void init() {
	for (int i = 123; i < 10000; i++) {
		int n1 = i / 1000;
		int n2 = i % 1000 / 100;
		int n3 = i % 100 / 10;
		int n4 = i % 10;
		if (n1 != n2 && n1 != n3 && n1 != n4 && n2 != n3 && n2 != n4 && n3 != n4) {
			number[idx++] = i;
			isValid[i] = true;
		}
	}
}

Result cmp(int t1, int t2) {
	Result r = { 0, 0 };

	int check[10] = { 0, };

	for (int i = 0; i < 4; i++) {
		int p11 = t1 % 10;
		int p21 = t2 % 10;
		if (p11 == p21) {
			r.strike++;
		}
		else {
			check[p11]++;
			if (check[p11] == 2)
				r.ball++;
			check[p21]++;
			if (check[p21] == 2)
				r.ball++;
		}
		t1 /= 10;
		t2 /= 10;
	}
	return r;

}

void doUserImplementation(int guess[]) {
	idx = 0;
	init();
	int i = 0;
	while (1) {
		int ans;
		for (; i < 5041; i++) {
			ans = number[i];
			if (isValid[ans] == true) {
				guess[0] = ans / 1000;
				guess[1] = ans % 1000 / 100;
				guess[2] = ans % 100 / 10;
				guess[3] = ans % 10;
				break;
			}
		}
		Result result = query(guess);
		if (result.strike == 4)
			return;
		isValid[ans] = false;

		//같은 것들이 있다면 모두 invalid시킴
		for (int j = i + 1; j < 5041; j++) {
			int test = number[j];
			if (isValid[test]) {
				Result rst = cmp(test, ans);
				if (rst.strike != result.strike || rst.ball != result.ball)
					isValid[test] = false;
			}
		}


	}

	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.

}
