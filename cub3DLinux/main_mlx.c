
#include "includes/cub3d.h"
#include "mlx/mlx.h"
#include "mlx/mlx_int.h"

int main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "mlxtest");
    mlx_loop(mlx);
    return (0);
}