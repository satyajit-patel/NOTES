class Solution {

	vector<double> compute(double a, double b)
	{
		double div1 = (b == 0) ? -100000 : a / b;
		double div2 = (a == 0) ? -100000 : b / a;

		return {a + b, a - b, b - a, a * b, div1, div2};
	}


	bool util(vector<double> &v)
	{
		if (v.size() == 1)
			return abs(v[0] - 24) <= 0.001;

		for (int i = 0; i < v.size(); ++i)
			for (int j = i + 1; j < v.size(); ++j)
			{
				vector<double> v2;

				for (int id = 0; id < v.size(); ++id)
					if (id != i and id != j)
						v2.push_back(v[id]);

				auto vals = compute(v[i], v[j]);

				for (double num : vals)
				{
					v2.push_back(num);

					if (util(v2))
						return true;

					v2.pop_back();
				}
			}

		return false;
	}

public:
	bool judgePoint24(vector<int>& cards) {
		vector<double> temp;

		for (int i : cards)
			temp.push_back(i);

		return util(temp);
	}
};