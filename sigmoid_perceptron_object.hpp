#ifndef sigmoid_perceptron_object_h
    #define sigmoid_perceptron_object_h

    #include <cmath>

    class sigmoid_perceptron
    {
        double *_data,**_w,*_wt,*_output;
        int _dataSize,_outputSize;
    public:
        sigmoid_perceptron(int dataSize, int outputSize)
        {
            int i,j;

            _dataSize = dataSize;
            _outputSize = outputSize;
            _data = (double*)malloc(dataSize * sizeof(double));
            _w = (double**)malloc(dataSize * sizeof(double*));
            _wt = (double*)malloc(outputSize * sizeof(double));
            _output = (double*)malloc(outputSize * sizeof(double));

            for(i = 0; i < dataSize; i++)
            {
                _w[i] = (double*)malloc(outputSize * sizeof(double));
            }

            for(i = 0; i < dataSize; i++)
            {
                _data[i] = (double)0;

                for(j = 0; j < outputSize; j++)
                {
                    _w[i][j] = (double)0;
                }
            }

            for(i = 0; i < outputSize; i++)
            {
                _wt[i] = (double)0;
            }
        }

        void fire(double *data)
        {
            int i,j;

            for(i = 0; i < _outputSize; i++)
            {
                _output[i] = _wt[i];

                for(j = 0; j < _dataSize; j++)
                {
                    _output[i] += data[j] * _w[j][i];
                }

                _output[i] = ((db)1 / ((db)1 + exp(_output[i])));
            }
        }

        void learn(double *data, double *expect, double alpha)
        {
            int i,j;
            fire(data);

            for(i = 0; i < _outputSize; i++)
            {
                _wt[i] += alpha * (expect[i] - _output[i]) * (_output[i]) * (1 - _output[i]);

                for(j = 0; j < _dataSize; j++)
                {
                    _w[j][i] += alpha * (expect[i] - _output[i]) * (data[j]) * (_output[i]) * (1 - _output[i]);
                }
            }
        }

        int output(void)
        {
            double M;
            int i,MP;

            M = _output[0];
            MP = 0;

            for(i = 1; i < _outputSize; i++)
            {
                if(_output[i] > M)
                {
                    M = _output[i];
                    MP = i;
                }
            }

            return MP;
        }

        ~sigmoid_perceptron(void)
        {
            int i;

            free(_data);
            free(_wt);
            free(_output);

            for(i = 0; i < _dataSize; i++)
            {
                free(_w[i]);
            }

            free(_w);
        }
    };
#endif
