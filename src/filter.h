#pragma once


namespace filter {

	class p_filter final : public CNdisApi {

	private:
		int filter_in, filter_out;

	public:
		//template<typename F1, typename F2>
		//p_filter(F1 in, F2 out) :
		p_filter(int in=0, int out=0) {
			std::cout << "rar";
			filter_in = in;
			filter_out = out;
		}

	};

}