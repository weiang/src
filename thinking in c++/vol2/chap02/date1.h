#ifndef DATE_H_
#define DATE_H_

class date {
	public:
		date(int year, int month, int day) : year(year), month(month), day(day) 
		{
		}

		date(const string& s) 
		{



		int get_month() const 
		{
			return month;
		}

		int get_day() const
		{
			return day;
		}

		int get_year() const 
		{
			return year;
		}

	private:
		int year, month, day;
};


#endif // DATE_H_
