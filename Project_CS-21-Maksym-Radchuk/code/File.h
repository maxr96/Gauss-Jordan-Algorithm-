class File{
      protected:
          int NEQ, N1;
          float **A;    
      public:
             virtual void fromFile() = 0;
             virtual void inFile() = 0;
             virtual void printFile() = 0;
             };
