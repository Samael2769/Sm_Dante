

typedef struct map_s
{
    int **map;
    int size_x;
    int size_y;
} map_t;

int **depth_first_backtracking(map_t *map);
void print_map(int **map, int size_x, int size_y);
void free_map(int **map, int size_y);
int **init_map(int size_x, int size_y);