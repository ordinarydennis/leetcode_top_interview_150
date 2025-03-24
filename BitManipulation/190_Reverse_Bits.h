class Solution {
public:
	uint32_t reverseBits(uint32_t n) {

		uint32_t b = 1 << 31;
		uint32_t ret = 0;

		while (n)
		{
			if (n & 1)
				ret = ret | b;
			
			n = n >> 1;
			b = b >> 1;
		}

		return ret;
	}

};