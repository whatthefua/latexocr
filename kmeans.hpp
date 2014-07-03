#ifndef kmeans_hpp
    #define kmeans_hpp

    #include <vector>
    using namespace std;

    class kmeans_object
    {
        int _dimension,_n_centres;
        double *_centres;
        vector<double*> _points;
        vector<int>* _closest_centre;
        double *_tmp;
    public:
        //constructor
        //creates k mean object of points of dimension dimensions with centre cluster centres
        kmeans_object(int dimension, int centre)
        {
            _dimension = dimension;
            _n_centres = centre;
            _centres = (double*) malloc (centre * dimension * sizeof(double));
        }

        //add point into object
        void add_point(double *point)
        {
            int i;

            _tmp = (double*) malloc (_dimension * sizeof(double));

            for(i = 0; i < _dimension; i++)
            {
                _tmp[i] = point[i];
            }

            _points.push_back(_tmp);
        }

        int find_closest_centre(double* point)
        {

        }

        //calculates cluster centres for all points, returns without any operation if number of points is insufficient
        void calculate_centre()
        {
            if(_points.size() < _n_centres)
            {
                return;
            }

            int i,j,k,fcc;
            bool change_flag = 1;

            for(i = 0; i < _n_centres; i++)
            {
                for(j = 0; j < _dimension; j++)
                {
                    _centres[i * _dimension + j] = _points[i][j];
                }
            }

            _closest_centre = (vector<int>*) malloc(_centres * sizeof(vector<int>));

            while(change_flag)
            {
                change_flag = 0;

                for(i = 0; i < _n_centres; i++)
                {
                    _closest_centre[i].clear();
                }

                for(i = 0; i < _points.size(); i++)
                {
                    fcc = find_closest_centre(_points[i]);
                    _closest_centre[fcc].push_back(i);
                }

                for(i = 0; i < _n_centres; i++)
                {
                    for(j = 0; j < _closest_centre[i].size(); j++)
                    {

                    }
                }
            }
        }

        //destructor
        ~kmeans_object()
        {
            free(*_centres);
        }
    };
#endif
