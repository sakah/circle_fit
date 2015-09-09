/*
   layer   1      0     G      +       51.1673      51.4000      147.6046     396         12          190.400        0.2327      66.106       0.0000
   layer   2      1     F      -       52.0358      52.2000      147.8867     396        -12         -190.400        0.1642     -67.004       15.867
   layer   3      1     S      -       52.8333      53.0000      148.1688     396        -12         -190.400        0.1667     -67.899       15.867
   layer   4      2     F      +       53.5705      53.8000      148.4509     408         12          184.800        0.2295      66.778       15.400
   layer   5      2     S      +       54.3671      54.6000      148.7331     408         12          184.800        0.2329      67.640       15.400
   layer   6      3     F      -       55.1770      55.4000      149.0152     420        -12         -179.520        0.2230     -66.553       0.0000
   layer   7      3     S      -       55.9738      56.2000      149.2973     420        -12         -179.520        0.2262     -67.384       0.0000
   layer   8      4     F      +       56.7831      57.0000      149.5794     432         12          174.533        0.2169      66.327       14.544
   layer   9      4     S      +       57.5801      57.8000      149.8616     432         12          174.533        0.2199      67.129       14.544
   layer   10     5     F      -       58.3889      58.6000      150.1437     444        -12         -169.816        0.2111     -66.102       0.0000
   layer   11     5     S      -       59.1860      59.4000      150.4258     444        -12         -169.816        0.2140     -66.876       0.0000
   layer   12     6     F      +       59.9944      60.2000      150.7079     456         12          165.347        0.2056      65.877       0.0000
   layer   13     6     S      +       60.7917      61.0000      150.9900     456         12          165.347        0.2083      66.625       0.0000
   layer   14     7     F      -       61.5996      61.8000      151.2722     468        -12         -161.107        0.2004     -65.652       13.426
   layer   15     7     S      -       62.3970      62.6000      151.5543     468        -12         -161.107        0.2030     -66.376       13.426
   layer   16     8     F      +       63.2046      63.4000      151.8364     480         12          157.080        0.1954      65.428       0.0000
   layer   17     8     S      +       64.0021      64.2000      152.1185     480         12          157.080        0.1979      66.129       0.0000
   layer   18     9     F      -       64.8093      65.0000      152.4007     492        -12         -153.248        0.1907     -65.205       12.771
   layer   19     9     S      -       65.6069      65.8000      152.6828     492        -12         -153.248        0.1931     -65.884       12.771
   layer   20     10    F      +       66.4138      66.6000      152.9649     504         12          149.600        0.1862      64.982       0.0000
   layer   21     10    S      +       67.2115      67.4000      153.2470     504         12          149.600        0.1885      65.640       0.0000
   layer   22     11    F      -       68.0181      68.2000      153.5292     516        -12         -146.121        0.1819     -64.761       12.177
   layer   23     11    S      -       68.8159      69.0000      153.8113     516        -12         -146.121        0.1841     -65.398       12.177
   layer   24     12    F      +       69.6222      69.8000      154.0934     528         12          142.800        0.1778      64.540       0.0000
   layer   25     12    S      +       70.4201      70.6000      154.3755     528         12          142.800        0.1799      65.158       0.0000
   layer   26     13    F      -       71.2261      71.4000      154.6576     540        -12         -139.626        0.1739     -64.319       11.636
   layer   27     13    S      -       72.0241      72.2000      154.9398     540        -12         -139.626        0.1759     -64.920       11.636
   layer   28     14    F      +       72.8298      73.0000      155.2219     552         12          136.591        0.1702      64.100       0.0000
   layer   29     14    S      +       73.6280      73.8000      155.5040     552         12          136.591        0.1720      64.683       0.0000
   layer   30     15    F      -       74.3733      74.6000      155.7861     564        -14         -155.966        0.2267     -74.472       0.0000
   layer   31     15    S      -       75.1709      75.4000      156.0683     564        -14         -155.966        0.2291     -75.132       0.0000
   layer   32     16    F      +       75.9780      76.2000      156.3504     576         14          152.716        0.2220      74.220       0.0000
   layer   33     16    S      +       76.7756      77.0000      156.6325     576         14          152.716        0.2244      74.862       0.0000
   layer   34     17    F      -       77.5825      77.8000      156.9146     588        -14         -149.600        0.2175     -73.969       10.686
   layer   35     17    S      -       78.3802      78.6000      157.1968     588        -14         -149.600        0.2198     -74.593       10.686
   layer   36     18    F      +       79.1868      79.4000      157.4789     600         14          146.608        0.2132      73.719       0.0000
   layer   37     18    S      +       79.9846      80.2000      157.7610     600         14          146.608        0.2154      74.326       0.0000
   layer   38     19    F      -       80.7909      81.0000      158.0431     612        -14         -143.733        0.2091     -73.470       10.267
   layer   39     19    G      -       81.5889      81.8000      158.3252     612        -14         -143.733        0.2111     -74.061       10.267
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>

#include "TCanvas.h"
#include "TH2F.h"
#include "TF1.h"
#include "TMarker.h"
#include "InputROOT.h"
#include "TGraphErrors.h"
#include "TEllipse.h"
#include "TMinuit.h"

//static double sqrt2(double a, double b)  { return TMath::Sqrt(a*a+b*b); }
static double sqrt2minus(double a, double b) 
{ 
   if (a<b) return 0.0;
   return TMath::Sqrt(a*a-b*b); 
}

static struct config* g_config;
int g_nhits;
double g_xhits[1000];
double g_yhits[1000];
double g_zhits[1000];
int    g_hits_ilayer[1000];
int    g_hits_icell[1000];
double g_xsig;
double g_ysig;
void func_circ(Int_t &npar, Double_t *gin, Double_t &f, Double_t *x, Int_t iflag)
{
   double x0 = x[0];
   double y0 = x[1];
   double R  = x[2];
   double chi2 = 0;
   for (int ihit=0; ihit<g_nhits; ihit++) {
      double x1 = g_xhits[ihit] - x0;
      double y1 = g_yhits[ihit] - y0;
      double theta = TMath::ATan2(y1, x1);
      double xexp = R * TMath::Cos(theta);
      double yexp = R * TMath::Sin(theta);
      double dx = (xexp-x1)/g_xsig;
      double dy = (yexp-y1)/g_ysig;
      chi2 += dx*dx + dy*dy;
   }
   //printf("chi2 %f\n", chi2);
   f = chi2;
}
void func_helix(Int_t &npar, Double_t *gin, Double_t &f, Double_t *x, Int_t iflag)
{
   double x0 = x[0];
   double y0 = x[1];
   double R  = x[2];
   double rad0  = x[3];
   double L  = x[4];
   double chi2 = 0;

   double w_x;
   double w_y;
   double w_z;
   for (int ihit=0; ihit<g_nhits; ihit++) {

      // calculate w_x/w_y using previous result
      double xhit = g_xhits[ihit];
      double yhit = g_yhits[ihit];
      double ddx = (xhit - x0)/R;
      double ddy = (yhit - y0)/R;
      double rad = TMath::ATan2(ddy,ddx);
      w_z = (rad - rad0)*L;

      int ilayer = g_hits_ilayer[ihit];
      int icell = g_hits_icell[ihit];
      config_get_wire_pos(g_config, ilayer, LAYER_TYPE_SENSE, icell, WIRE_TYPE_SENSE, w_z, "center", &w_x, &w_y);

      double xexp = x0 + R * TMath::Cos(rad0 + w_z/L);
      double yexp = y0 + R * TMath::Sin(rad0 + w_z/L);
      double dx = (xexp-w_x)/g_xsig;
      double dy = (yexp-w_y)/g_ysig;
      chi2 += dx*dx + dy*dy;

      // update hit position for next fit
      g_xhits[ihit] = w_x;
      g_yhits[ihit] = w_y;
      g_zhits[ihit] = w_z;
   }
   //printf("chi2 %f\n", chi2);
   f = chi2;
}

struct Circle
{
   int nhits;
   double xhits[1000];
   double yhits[1000];
   double radius[20];
   int hits_ilayer[1000];
   int hits_icell[1000];

   int line_color;

   TMinuit* minuit;
   double chi2;
   Circle()
   {
      nhits = 0;

      int n = 0;
      radius[n++] = 51.4000;
      radius[n++] = 53.0000;
      radius[n++] = 54.6000;
      radius[n++] = 56.2000;
      radius[n++] = 57.8000;
      radius[n++] = 59.4000;
      radius[n++] = 61.0000;
      radius[n++] = 62.6000;
      radius[n++] = 64.2000;
      radius[n++] = 65.8000;
      radius[n++] = 67.4000;
      radius[n++] = 69.0000;
      radius[n++] = 70.6000;
      radius[n++] = 72.2000;
      radius[n++] = 73.8000;
      radius[n++] = 75.4000;
      radius[n++] = 77.0000;
      radius[n++] = 78.6000;
      radius[n++] = 80.2000;
      radius[n++] = 81.8000;

      minuit = new TMinuit(3);
      minuit->SetFCN(func_circ);
      g_xsig = 1.0;
      g_ysig = 1.0;
   };
   void copy_hits(Circle& other)
   {
      nhits = other.nhits;
      for (int ihit=0; ihit<nhits; ihit++) {
         xhits[ihit] = other.xhits[ihit];
         yhits[ihit] = other.yhits[ihit];
         hits_ilayer[ihit] = other.hits_ilayer[ihit];
         hits_icell[ihit]  = other.hits_icell[ihit];
      }
   };
   void add_hit(int ilayer, int icell, double x, double y)
   {
      hits_ilayer[nhits] = ilayer;
      hits_icell[nhits] = icell;
      xhits[nhits] = x;
      yhits[nhits] = y;
      nhits++;
   };
   void add_hits(Circle& c1, Circle& c2)
   {
      for (int ihit=0; ihit<c1.nhits; ihit++) {
         hits_ilayer[nhits] = c1.hits_ilayer[ihit];
         hits_icell[nhits] = c1.hits_icell[ihit];
         xhits[nhits] =  c1.xhits[ihit];
         yhits[nhits] = c1.yhits[ihit];
         nhits++;
      }
      for (int ihit=0; ihit<c2.nhits; ihit++) {
         hits_ilayer[nhits] = c2.hits_ilayer[ihit];
         hits_icell[nhits] = c2.hits_icell[ihit];
         xhits[nhits] =  c2.xhits[ihit];
         yhits[nhits] = c2.yhits[ihit];
         nhits++;
      }
   };
   double x0_fit;
   double y0_fit;
   double R_fit;
   double x0_ini;
   double y0_ini;
   double R_ini;
   double x0_step;
   double y0_step;
   double R_step;
   double get_rad_fit(int ihit) 
   { 
      double dx = (xhits[ihit] - x0_fit)/R_fit;
      double dy = (yhits[ihit] - y0_fit)/R_fit;
      return TMath::ATan2(dy,dx);
   };
   double get_rad1_fit() { return get_rad_fit(0); };
   double get_rad2_fit() { return get_rad_fit(nhits-1); };
   double get_deg1_fit() { return get_rad1_fit()/TMath::Pi()*180.0; };
   double get_deg2_fit() { return get_rad2_fit()/TMath::Pi()*180.0; };
   double get_pt_fit()
   { 
      // p (GeV) = 0.3 * B (T) * R (m)
      // pm (MeV) * 1e-3 =  0.3 * B (T) * r (cm)*1e-2
      double B = 1.0; // T
      double pt = 3.0*B*R_fit; // MeV/c
      return pt;
   };
   void set_line_color(int col)
   {
      line_color = col;
   };
   void clear()
   {
      nhits = 0;
   };
   void set_fit_inipar()
   {
      x0_ini = 20;
      y0_ini = -5;
      R_ini = 40;
      //circ1.x0_fit = 20;
      //circ1.y0_fit = -5;
      //circ1.R_fit = 40;

      x0_step = 1;
      y0_step = 1;
      R_step = 1;
   };
   void fit_circ()
   {
      // copy to global values
      g_nhits = nhits;
      for (int ihit=0; ihit<nhits; ihit++) {
         g_xhits[ihit] = xhits[ihit];
         g_yhits[ihit] = yhits[ihit];
      }

      Int_t ierflag;
      Double_t arglist[10];
      TString Tag[3];
      Double_t var[3];
      Double_t verr[3];
      Double_t bnd1, bnd2;
      Int_t ivarbl;

      minuit->mnparm(0, "x0", x0_ini, x0_step, 0, 0, ierflag);
      minuit->mnparm(1, "y0", y0_ini, y0_step, 0, 0, ierflag);
      minuit->mnparm(2 ,"R",  R_ini,  R_step,  0, 0, ierflag);
      arglist[0] = 1; // use chi2
      minuit->mnexcm("SET ERR", arglist, 1, ierflag);
      arglist[0] = 1000; // do at least 1000 function calls
      arglist[1] = 0.1;  // tolerance = 0.1
      minuit->mnexcm("MIGRAD", arglist, 2, ierflag);
      for (int i=0; i<3; i++) {
         minuit->mnpout(i, Tag[i], var[i], verr[i], bnd1, bnd2, ivarbl);
         printf("i %d %f +/- %f\n", i, var[i], verr[i]);
      }
      // Result
      Double_t amin,edm,errdef;
      Int_t nvpar,nparx,icstat;
      minuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
      chi2 = amin;

      x0_fit = var[0]; //cm
      y0_fit = var[1]; //cm
      R_fit  = var[2]; // cm

      printf("R_fit %f\n", R_fit);
      printf("pt_fit %f\n", get_pt_fit());
   };
   void print_fit_result()
   {
      printf("x0 %f y0 %f R %f pt %f (MeV/c) deg1 %f deg2 %f\n", x0_fit, y0_fit, R_fit, get_pt_fit(), get_deg1_fit(), get_deg2_fit());
   };
   // Draw
   void draw_xy_canvas()
   {
      TH2F*  h2 = new TH2F("fname","", 100, -100, 100, 100, -100, 100);
      h2->SetStats(0);
      h2->Draw();
   };
   void draw_xy_hits_fits()
   {
      draw_radius();
      draw_xy_hits();
      draw_xy_fit();
   };
   void draw_radius()
   {
      for (int ilayer=0; ilayer<20; ilayer++) {
         if (ilayer%2==0) continue;
         TEllipse* e = new TEllipse(0,0,radius[ilayer]);
         e->SetFillStyle(0);
         e->SetLineWidth(1);
         e->SetLineStyle(1);
         e->Draw();
      }
   };
   void draw_xy_hits()
   {
      for (int ihit=0; ihit<nhits; ihit++) {
         TMarker* m = new TMarker(xhits[ihit], yhits[ihit], 8);
         m->Draw();
      }
   };
   void draw_xy_fit()
   {
      TMarker* m = new TMarker(x0_fit, y0_fit, 8);
      m->SetMarkerColor(line_color);
      m->Draw();

      TEllipse* e = new TEllipse(x0_fit, y0_fit, R_fit);
      e->SetFillStyle(0);
      e->SetLineWidth(1);
      e->SetLineStyle(1);
      e->SetLineColor(line_color);
      e->Draw();
   };
};

struct Helix
{
   int nhits;
   double xhits[1000];
   double yhits[1000];
   double zhits[1000];
   double radius[20];
   int hits_ilayer[1000];
   int hits_icell[1000];

   int line_color;

   TMinuit* minuit;
   double chi2;
   double x0_fit;
   double y0_fit;
   double R_fit;
   double rad0_fit;
   double L_fit;

   double x0_ini;
   double y0_ini;
   double R_ini;
   double rad0_ini;
   double L_ini;

   double x0_step;
   double y0_step;
   double R_step;
   double rad0_step;
   double L_step;

   double get_pt_fit()
   { 
      // p (GeV) = 0.3 * B (T) * R (m)
      // pm (MeV) * 1e-3 =  0.3 * B (T) * r (cm)*1e-2
      double B = 1.0; // T
      double pt = 3.0*B*R_fit; // MeV/c
      return pt;
   };
   double get_pz_fit()
   { 
      // p (GeV) = 0.3 * B (T) * R (m)
      // pm (MeV) * 1e-3 =  0.3 * B (T) * r (cm)*1e-2
      double B = 1.0; // T
      double pz = 3.0*B*L_fit; // MeV/c
      return pz;
   };
   Helix()
   {
      nhits = 0;

      int n = 0;
      radius[n++] = 51.4000;
      radius[n++] = 53.0000;
      radius[n++] = 54.6000;
      radius[n++] = 56.2000;
      radius[n++] = 57.8000;
      radius[n++] = 59.4000;
      radius[n++] = 61.0000;
      radius[n++] = 62.6000;
      radius[n++] = 64.2000;
      radius[n++] = 65.8000;
      radius[n++] = 67.4000;
      radius[n++] = 69.0000;
      radius[n++] = 70.6000;
      radius[n++] = 72.2000;
      radius[n++] = 73.8000;
      radius[n++] = 75.4000;
      radius[n++] = 77.0000;
      radius[n++] = 78.6000;
      radius[n++] = 80.2000;
      radius[n++] = 81.8000;

      minuit = new TMinuit(5);
      minuit->SetFCN(func_helix);
      g_xsig = 1.0;
      g_ysig = 1.0;
   };
   void set_line_color(int col)
   {
      line_color = col;
   };
   void clear()
   {
      nhits = 0;
   };
   void add_hits(Circle& c1)
   {
      int n = c1.nhits;
      for (int ihit=0; ihit<n; ihit++) {
         xhits[nhits] = c1.xhits[ihit];
         yhits[nhits] = c1.yhits[ihit];
         zhits[nhits] = 0.0; // zhits will be set afer fitting
         hits_ilayer[nhits] = c1.hits_ilayer[ihit];
         hits_icell[nhits]  = c1.hits_icell[ihit];
         nhits++;
      }
   };
   void copy_hits(Helix& other)
   {
      nhits = other.nhits;
      for (int ihit=0; ihit<nhits; ihit++) {
         xhits[ihit] = other.xhits[ihit];
         yhits[ihit] = other.yhits[ihit];
         zhits[ihit] = other.zhits[ihit];
         hits_ilayer[ihit] = other.hits_ilayer[ihit];
         hits_icell[ihit]  = other.hits_icell[ihit];
      }
   };
   void set_fit_inipar(double x0, double y0, double R, double rad0, double L)
   {
      x0_ini = x0;
      y0_ini = y0;
      R_ini = R;
      rad0_ini = rad0;
      L_ini = L;

      x0_step = 1;
      y0_step = 1;
      R_step = 1;
      rad0_step = 1;
      L_step = 1;
   };
   void fit_helix()
   {
      // copy to global values
      g_nhits = nhits;
      for (int ihit=0; ihit<nhits; ihit++) {
         g_xhits[ihit] = xhits[ihit];
         g_yhits[ihit] = yhits[ihit];
         g_zhits[ihit] = 0.0; // zhits will be set in func_helix using xypos
      }

      Int_t ierflag;
      Double_t arglist[10];
      TString Tag[3];
      Double_t var[3];
      Double_t verr[3];
      Double_t bnd1, bnd2;
      Int_t ivarbl;

      minuit->mnparm(0, "x0", x0_ini, x0_step, 0, 0, ierflag);
      minuit->mnparm(1, "y0", y0_ini, y0_step, 0, 0, ierflag);
      minuit->mnparm(2 ,"R",  R_ini,  R_step,  0, 0, ierflag);
      minuit->mnparm(3 ,"rad0",  rad0_ini,  rad0_step,  0, 0, ierflag);
      minuit->mnparm(4 ,"L",     L_ini,  L_step,  0, 0, ierflag);
      arglist[0] = 1; // use chi2
      minuit->mnexcm("SET ERR", arglist, 1, ierflag);
      arglist[0] = 1000; // do at least 1000 function calls
      arglist[1] = 0.1;  // tolerance = 0.1
      minuit->mnexcm("MIGRAD", arglist, 2, ierflag);
      for (int i=0; i<5; i++) {
         minuit->mnpout(i, Tag[i], var[i], verr[i], bnd1, bnd2, ivarbl);
         printf("i %d %f +/- %f\n", i, var[i], verr[i]);
      }
      // Result
      Double_t amin,edm,errdef;
      Int_t nvpar,nparx,icstat;
      minuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
      chi2 = amin;

      x0_fit = var[0]; //cm
      y0_fit = var[1]; //cm
      R_fit  = var[2]; // cm
      rad0_fit  = var[3]; // rad
      L_fit  = var[4]; // cm

      printf("R_fit %f pt_fit %f\n", R_fit, get_pt_fit());
      printf("L_fit %f pz_fit %f\n", L_fit, get_pz_fit());
   };
   void print_fit_result()
   {
      printf("x0 %f y0 %f R %f pt %f (MeV/c) rad0 %f L %f pz %f\n", x0_fit, y0_fit, R_fit, get_pt_fit(), rad0_fit, L_fit, get_pz_fit());
   };

   // Draw
   void draw_xy_canvas()
   {
      TH2F*  h2 = new TH2F("fname","", 100, -100, 100, 100, -100, 100);
      h2->SetStats(0);
      h2->Draw();

      draw_radius();
   };
   void draw_xz_canvas()
   {
      TH2F*  h2 = new TH2F("fname-xz","", 100, -100, 100, 100, -100, 100);
      h2->SetStats(0);
      h2->Draw();
   };
   void draw_yz_canvas()
   {
      TH2F*  h2 = new TH2F("fname-yz","", 100, -100, 100, 100, -100, 100);
      h2->SetStats(0);
      h2->Draw();
   };
   void draw_xy_hits_fits()
   {
      draw_radius();
      draw_xy_hits();
      draw_xy_fit();
   };
   void draw_xz_hits_fits()
   {
      draw_xz_hits();
      draw_xz_fit();
   };
   void draw_yz_hits_fits()
   {
      draw_yz_hits();
      draw_yz_fit();
   };
   void draw_radius()
   {
      for (int ilayer=0; ilayer<20; ilayer++) {
         if (ilayer%2==0) continue;
         TEllipse* e = new TEllipse(0,0,radius[ilayer]);
         e->SetFillStyle(0);
         e->SetLineWidth(1);
         e->SetLineStyle(1);
         e->Draw();
      }
   };
   void draw_xy_hits()
   {
      for (int ihit=0; ihit<nhits; ihit++) {
         TMarker* m = new TMarker(xhits[ihit], yhits[ihit], 8);
         m->Draw();
      }
   };
   void draw_xz_hits()
   {
      for (int ihit=0; ihit<nhits; ihit++) {
         TMarker* m = new TMarker(xhits[ihit], zhits[ihit], 8);
         m->Draw();
      }
   };
   void draw_yz_hits()
   {
      for (int ihit=0; ihit<nhits; ihit++) {
         TMarker* m = new TMarker(xhits[ihit], zhits[ihit], 8);
         m->Draw();
      }
   };
   void draw_xy_fit()
   {
      TMarker* m = new TMarker(x0_fit, y0_fit, 8);
      m->SetMarkerColor(line_color);
      m->Draw();

      TEllipse* e = new TEllipse(x0_fit, y0_fit, R_fit);
      e->SetFillStyle(0);
      e->SetLineWidth(1);
      e->SetLineStyle(1);
      e->SetLineColor(line_color);
      e->Draw();
   };
   void draw_xz_fit()
   {
      // x0 + R*cos(rad0 + z/L)
      TF1* f1 = new TF1("f1", "[0] + [1]*cos([2]+x/[3])", -100, 100);
      f1->SetLineWidth(1);
      f1->SetLineStyle(1);
      f1->SetLineColor(line_color);
      f1->SetParameters(x0_fit, R_fit, rad0_fit, L_fit);
      f1->Draw();
   };
   void draw_yz_fit()
   {
      // x0 + R*cos(rad0 + z/L)
      TF1* f1 = new TF1("f1", "[0] + [1]*sin([2]+x/[3])", -100, 100);
      f1->SetLineWidth(1);
      f1->SetLineStyle(1);
      f1->SetLineColor(line_color);
      f1->SetParameters(y0_fit, R_fit, rad0_fit, L_fit);
      f1->Draw();
   };
};

struct TwoCircle
{
   double dr;
   double deg;
   void calc(Circle& c1, Circle& c2)
   {
      double dx = c2.x0_fit - c1.x0_fit;
      double dy = c2.y0_fit - c1.y0_fit;
      dr = TMath::Sqrt(dx*dx+dy*dy);
      double theta = TMath::ATan2(dy, dx);
      deg = theta/TMath::Pi()*180.0;
   };
   void print()
   {
      printf("dr %f deg %f\n", dr, deg);
   };
};


double estimate_z1(double dr)
{
   // Following formula is estimated by 
   // fitting z vs dr
   return (-51.3563+7.74943*dr);
}
double estimate_z2(double z1, double drad, double if_pz)
{
   // pz = MeV/c
   // L = cm
   double B = 1.0; // T
   double L = if_pz/(3.0*B); // cm
   printf("estimate_z2 if_pz %f (MeV/c) L %f cm\n", if_pz, L);
   return z1 + L * drad;
}
double estimate_pz(double z1, double z2, double drad)
{
   // drad is always positive
   // L is either positive or netive
   double L = (z2-z1)/drad; // cm
   double B = 1.0; // T
   double pz = 3.0*B*L; // MeV/c
   return pz;
}

int main(int argc, char** argv)
{
   if (argc != 8) {
      fprintf(stderr,"Usage %s <input.root> <wire_config.txt> <sample_type> <t2r_type> <rdrift_err_cm> <posSmear_cm> <momSmear_percent>\n", argv[0]);
      return -1;
   }
   char* input_root = argv[1];
   char* wire_config_txt = argv[2];
   char* sample_type = argv[3];
   char* t2r_type = argv[4];
   double rdrift_err_cm = atof(argv[5]);
   double posSmear_cm = atof(argv[6]);
   double momSmear_percent = atof(argv[7]);

   InputROOT inROOT(input_root, wire_config_txt, sample_type, t2r_type, rdrift_err_cm, posSmear_cm, momSmear_percent);
   g_config = inROOT.getConfig();
   //int total = inROOT.getEntries();
   //int total = 100;

   double w_x1;
   double w_y1;
   double w_z1;
   double w_x2;
   double w_y2;
   double w_z2;
   double w_x;
   double w_y;
   double w_z;

   struct Circle circ1; // odd-layer
   struct Circle circ2; // even-layer
   circ1.set_line_color(kRed);
   circ2.set_line_color(kBlue);
   struct Helix helix;
   helix.set_line_color(kMagenta);

   FILE* fpout = fopen("debug.txt","w");
   char title[12];
   int iev1=4, iev2=5;
   //int iev1=14, iev2=15;
   //int iev1=2, iev2=3;
   //int iev1=0, iev2=3;
   //int iev1=0, iev2=50;
   //int iev1=0, iev2=2000;
   for (int iev=iev1; iev<iev2; iev++) { 
      fprintf(stderr,"iev %d\n", iev);

      inROOT.getEntry(iev);
      bool directHit = inROOT.InDirectHitAtTriggerCounter();
      if (!directHit) continue;

      int numHits = inROOT.getNumHits();
      if (numHits==0) continue;

      circ1.clear();
      circ2.clear();

      //printf("iev %d numHits %d\n", iev, numHits );

      double zpos = -1;
      int icell1 = -1;
      int icell2 = -1;
      for (int ihit=0; ihit<numHits; ihit++) {
         int ilayer = inROOT.getIlayer(ihit);
         int icell = inROOT.getIcell(ihit);
         int iturn = inROOT.getIturn(ihit);
         if (iturn!=0) break; 
         //printf("ilayer %d icell %d iturn %d\n", ilayer, icell, iturn);

         inROOT.getWirePosAtEndPlates(ihit, w_x1, w_y1, w_z1, w_x2, w_y2, w_z2);
         inROOT.getWirePosAtHitPoint(ihit, w_x, w_y, w_z);

         if (ilayer%2==1) circ1.add_hit(ilayer, icell,w_x1, w_y1);
         if (ilayer%2==0) circ2.add_hit(ilayer, icell,w_x1, w_y1);
      }

      circ1.fit_circ();
      circ2.fit_circ();
      circ1.print_fit_result();
      circ2.print_fit_result();

      struct TwoCircle tc;
      tc.calc(circ1, circ2);
      tc.print();

      double z1_fit = estimate_z1(tc.dr);
      double pa_guess = 104.0;
      // pz_guess should be tested both positive and negative case
      double pz_guess = sqrt2minus(pa_guess, circ1.get_pt_fit()); // assume positive
      double B = 1.0; // T
      double L_guess = pz_guess/(3.0*B);
      double rad0_guess = circ1.get_rad1_fit() - z1_fit/L_guess;
      printf("z1_fit %f pz_guess %f L_guess %f rad0_guess %f (deg)\n", z1_fit, pz_guess, L_guess, rad0_guess/TMath::Pi()*180.0);

      helix.clear();
      helix.add_hits(circ1);
      helix.add_hits(circ2);
      helix.set_fit_inipar(circ1.x0_fit, circ1.y0_fit, circ1.R_fit, rad0_guess, L_guess);
      helix.fit_helix();
      helix.print_fit_result();

      TVector3 mcPos;
      TVector3 mcMom;
      inROOT.getPosMom(0, mcPos, mcMom);
      double mc_z  = mcPos.Z();
      double mc_pt = sqrt2(mcMom.X(), mcMom.Y())*1e3; // GeV -> MeV
      double mc_pz = mcMom.Z()*1e3; // GeV -> MeV
      fprintf(fpout, "%5d %f %f %f %f %f %f %f %f %f\n", iev, tc.dr, tc.deg, mc_z, z1_fit, mc_pt, helix.get_pt_fit(), mc_pz, helix.get_pz_fit(), helix.chi2);
      fflush(fpout);

      fprintf(stdout, "## iev %5d tc.dr %f tc.deg %f mc_z %f z1_fit %f mc_pt %f helix.pt_fit %f mc_pz %f helix.pz_fit %f helix.chi2 %f\n", 
            iev, tc.dr, tc.deg, mc_z, z1_fit, mc_pt, helix.get_pt_fit(), mc_pz, helix.get_pz_fit(), helix.chi2);

      TCanvas* c1 = new TCanvas("c1","",2000,2000);
      c1->Divide(2,2);
      c1->cd(1); circ1.draw_xy_canvas(); circ1.draw_xy_hits_fits();
      c1->cd(2); circ2.draw_xy_canvas(); circ2.draw_xy_hits_fits();
      c1->cd(3); circ1.draw_xy_canvas(); circ1.draw_xy_hits_fits(); circ2.draw_xy_hits_fits();
      c1->Print(Form("pdf/circle/%05d.pdf", iev));

      TCanvas* c2 = new TCanvas("c2","",2000,2000);
      c2->Divide(2,2);
      c2->cd(1); helix.draw_xy_canvas(); helix.draw_xy_hits_fits();
      c2->cd(2); helix.draw_xz_canvas(); helix.draw_xz_hits_fits();
      c2->cd(3); helix.draw_yz_canvas(); helix.draw_yz_hits_fits();
      c2->Print(Form("pdf/helix/%05d.pdf", iev));

   }
   fclose(fpout);

   return 0;
}
