#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

#include <vector>
#include <string>
#include <stdexcept>

class core {
	friend class student_info;

public:
	core();
	core(std::istream&);
	virtual ~core() { }
	std::string name() const;
	virtual double grade() const;
	virtual std::istream& read(std::istream& in);
	bool valid() const;

protected:
	virtual core* clone() const { return new core(*this); }
	std::istream& read_common(std::istream& in);
	double midterm, final;
	std::vector<double> homework;

private:
	std::string n;
};

class grad : public core {
public: 
	grad();
	grad(std::istream&);
	double grade() const;
	std::istream& read(std::istream&);

protected:
	grad* clone() const { return new grad(*this); }

private:
	double thesis;
};

class student_info {
	public:
		student_info() : cp(0) { }
		student_info(std::istream& in) : cp(0) { read(in); }
		student_info(const student_info&);
		student_info& operator=(const student_info&);
		~student_info() { delete cp; }

		std::istream& read(std::istream&);
		
		std::string name() const 
		{
			if (cp) 
				return cp -> name();
			else 
				throw std::runtime_error("Uninitialized Student");
		}
		double grade() const 
		{
			if (cp )
				return cp -> grade();
			else 
				throw std::runtime_error("Uninitialized Student");
		}
	
		static bool compare(const student_info& a,
				            const student_info& b)
		{
			return a.name() < b.name();
		}

	private:
		core* cp;
};

#endif
