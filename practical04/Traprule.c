#include<stdio.h>
#include<math.h>


float deg_to_rad(float theta)
{

   return M_PI * theta / 180.0 ;

}


float trap_rule(float a, float b, int N, float function_array[N+1])
{
   // Find the area by trapezodial rule
   float sum = function_array[0]+function_array[N];
   int i = 0;
   // Calculate  the area points  x1, x2, x3,........x11 and add them up
   // as in the formula  using loops
   for (i = 1; i < N; i++)
   {
  
      sum = sum + 2*function_array[i];

   }
   return (b-a) * (sum) / (2 * N);

}



int main(void)
{

   float start = 0;
   float end = 60;
   int N = 12;
   float step_size = (end - start) / N;
   float tan_arr[N +1];
   
   int i=0;
   // Calculate the values of f(xi) where i = 0,.....,12
   //  and xi are in radians (as array elements)
   for (i = 0; i<=N; i++)
   {
    
       tan_arr[i] = tan(deg_to_rad(step_size*i));
   }
   float ans = trap_rule(deg_to_rad(start), deg_to_rad(end), N, tan_arr);
   // Approximated result
   printf("The approximate  answer is %f\n", ans);
   // Actual  result
   // Integral of tan is ln(2)
   printf("The actual value is %f\n", logf(2));

   return 0;
}

