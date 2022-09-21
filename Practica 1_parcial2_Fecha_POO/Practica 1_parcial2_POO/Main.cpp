#include<iostream>
#include<string>

class Date
{
private:
	std::string Fecha,Fecha2=Fecha;
	int Anio, Mes, Dia;

public:
	Date(std::string);

	void setFecha(std::string Fecha) {
		this->Fecha = Fecha;
	}

	int getAnio() {
		if (Anio > 9999) {
			Anio = 9999;
		}
		else if (Anio <= 0) {
			Anio = 1;
		}
		std::cout<<"Anio: " << Anio << " es un anio ";
		if (Anio % 4 == 0 and Anio % 100 != 0 or Anio % 400 == 0) //Condición de año bisiesto                                              
			std::cout << "Bisiesto" << std::endl;
		else
			std::cout << "No es bisiesto" << std::endl;

		return Anio;
	}

	int getMes() {
		if (Mes<=0)
		{
			Mes = 1;
		}
		else if(Mes >= 13)
		{
			Mes = 12;
		}
		
		return Mes;
	}
	

	int getDia() {
		
		return Dia;
	}
	void ValidarDia() {

		if (Mes >= 1 && Mes <= 12)
			if (Mes <= 0)
			{
				Mes = 1;
			}
			else if (Mes >= 13)
			{
				Mes = 12;
			}

			switch (Mes)
			{
			case  1:
			case  3:
			case  5:
			case  7:
			case  8:
			case 10:
			case 12: std::cout << "31"; 
				break;

			case  4:
			case  6:
			case  9:
			case 11: std::cout << "30"; 
				break;

			case  2: 
				if (Anio % 4 == 0 && Anio % 100 != 0 || Anio % 400 == 0)
					std::cout << "29";
				else
					std::cout << "28";
			}

	}
	
};

Date::Date(std::string fecha) {

	Fecha = fecha;
	
	Fecha2 = Fecha.substr(0, 4);
	Anio = stoi(Fecha2);

	Fecha2 = Fecha.substr(5, 6);
	Mes = stoi(Fecha2);
	
	Fecha2 = Fecha.substr(8, 9);
	Dia = stoi(Fecha2);
	
}

int main() {
	
	std::string Fecha,date;
	
	std::cout << "Fecha" << std::endl;
	std::cout << "ingrese la fecha YYYY/MM/DD" << std::endl;
	getline(std::cin, date);
	Date Newdate(date);

	std::cout <<"Anio: "<< Newdate.getAnio() << std::endl;
	std::cout << "Mes: " << Newdate.getMes() << std::endl;
	std::cout<<"Dia: ";
	Newdate.ValidarDia();
	std::cout << std::endl;

	return 0;
}