#include <stdio.h>
#include <math.h>

int main()
{
    printf("Problem 1.2_1\n\n");

    double dt=0.01;
    int size=4*M_PI/dt;
    double x[size];
    x[0]=1.0;
    double v[size];
    v[0]=0.0;
    x[1]=cos(dt);//(x[0]+dt*v[0]);
    v[1]=-sin(dt);//(v[0]-dt*x[1]);
    double t=0.0;
    int count=1;

    printf("x(%2.2f):  %f\tv(%2.2f):  %f\tExact x(%2.2f):  %f\tExact v(%2.2f):  %f\n\n",
               t,x[count],t,v[count],t,cos(t),t,-sin(t));

    for(t=0;t<(4*M_PI);t+=dt)
    {
        //x[count]=(x[count-1]+dt*v[count-1]);
        //v[count]=(v[count-1]-dt*x[count]);

        x[count+2]=(4*x[count+1])-(3*x[count])-(2*v[count]*dt);
        v[count+2]=-((4*v[count+1])-(3*v[count])+(2*x[count]*dt));
        //x[count]=(4*x[count-1])-(3*x[count-2])+(2*dt*((Ox*(dt*dt))-v[count-2]));
        //v[count]=(4*v[count-1])-(3*v[count-2])+(2*dt*((Ov*(dt*dt))-x[count-2]));
        //v[count]=((4*x[count]+dt-3*x[count]-x[count-1]+(2*dt))/2*dt)+O*(dt*dt);

        printf("x(%2.2f):  %f\tv(%2.2f):  %f\tExact x(%2.2f):  %f\tExact v(%2.2f):  %f\n\n",
               t,x[count],t,v[count],t,cos(t),t,-sin(t));
        count++;
    }

    return 0;
}
