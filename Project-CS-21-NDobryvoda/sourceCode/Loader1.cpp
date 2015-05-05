#include"loader.h"
#include"parser.h"

vector<Student> Loader::LoadStudentsDB(string _pathOfBD)
	{
		//����� �����, � ���� �������� ��'� � �������.
		vector<string> lines = vector<string>();	
		
		char* tmpLine = new char[200];
		
		ifstream* DBfile = new ifstream();
		
		
		// �������� �� ����������� ������� ��� �������� 
		DBfile->exceptions(fstream::badbit | fstream::failbit); 
			

		try{
			// �������� ����� � ������� try ��� ������������ �������� �������
			DBfile->open(_pathOfBD);

			// �������� ������ � ����� ������������ ��
			while(!DBfile->eof())
			{
				if(DBfile->getline(tmpLine,200))
					lines.push_back(string(tmpLine));
			}
		}
		// ���������� �������� ��������� ( ��������� ���������� ��� �������, ����� � ���������� )
		catch(fstream::failure e){
			cout << "Caught an ios_base::failure.\n"
                  << "Explanatory string: " << e.what() << '\n'
                  << "Error code: " << e.code() << '\n';
			system("pause");
			exit(1);
		}
		//��������� � ��������� ����
		DBfile->close();
		delete DBfile;
		DBfile = NULL;
		
		//����� ��������
		vector<Student> studentDB = vector<Student>();

		//��������� ������� ����� ������, ��������� ��'� � 
		//������� �������� � ����� ��������� �������� + �������� ���� � �����.
		for(int i=0;i<lines.size();i++)
			studentDB.push_back(Student(Parser::GetName(lines[i]),	Parser::GetRate(lines[i])));

		//��������� ����� ������ (�� ��� ����� �� �������)
		
		return studentDB;
	}