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

int g_nhits;
double g_xhits[1000];
double g_yhits[1000];
double g_xsig;
double g_ysig;
void func(Int_t &npar, Double_t *gin, Double_t &f, Double_t *x, Int_t iflag)
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
};

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
      minuit->SetFCN(func);
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
   void update_xypos(struct config* config, double z1, double z2)
   {
      double w_x;
      double w_y;
      for (int ihit=0; ihit<nhits; ihit++) {
         int ilayer = hits_ilayer[ihit];
         int icell = hits_icell[ihit];
         double zhit = z1 + ihit*(z2-z1)/nhits;
         config_get_wire_pos(config, ilayer, LAYER_TYPE_SENSE, icell, WIRE_TYPE_SENSE, zhit, "center", &w_x, &w_y);
         xhits[ihit] = w_x;
         yhits[ihit] = w_y;
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
   double rad1_fit;
   double rad2_fit;
   double deg1_fit;
   double deg2_fit;
   double pt_fit;
   void set_line_color(int col)
   {
      line_color = col;
   };
   void clear()
   {
      nhits = 0;
   };
   void calc_init()
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
   void fit()
   {
      // copy to global values
      g_nhits = nhits;
      for (int ihit=0; ihit<nhits; ihit++) {
         g_xhits[ihit] = xhits[ihit];
         g_yhits[ihit] = yhits[ihit];
      }
      calc_init();

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
      minuit->mnexcm("SET ERR", arglist, 1, ierflag);
      arglist[0] = 1000; // do at least 1000 function calls
      arglist[1] = 0.1;  // tolerance = 0.1
      minuit->mnexcm("MIGRAD", arglist, 2, ierflag);
      for (int i=0; i<3; i++) {
         minuit->mnpout(i, Tag[i], var[i], verr[i], bnd1, bnd2, ivarbl);
         printf("i %d %f +/- %f\n", i, var[i], verr[i]);
      }
      x0_fit = var[0]; //cm
      y0_fit = var[1]; //cm
      R_fit  = var[2]; // cm

      double B = 1.0; // T
      printf("R_fit %f\n", R_fit);
      pt_fit = 3.0*B*R_fit; // MeV/c
      // p (GeV) = 0.3 * B (T) * R (m)
      // pm (MeV) * 1e-3 =  0.3 * B (T) * r (cm)*1e-2

      printf("pt_fit %f\n", pt_fit);

      double dx1 = xhits[0] - x0_fit;
      double dy1 = yhits[0] - y0_fit;
      double dx2 = xhits[nhits-1] - x0_fit;
      double dy2 = yhits[nhits-1] - y0_fit;
      rad1_fit = TMath::ATan2(dy1,dx1);
      rad2_fit = TMath::ATan2(dy2,dx2);
      deg1_fit = rad1_fit/TMath::Pi()*180.0;
      deg2_fit = rad2_fit/TMath::Pi()*180.0;
   };
   void draw_fit_circle()
   {
      TEllipse* e = new TEllipse(x0_fit, y0_fit, R_fit);
      e->SetFillStyle(0);
      e->SetLineWidth(1);
      e->SetLineStyle(1);
      e->SetLineColor(line_color);
      e->Draw();
   };
   void print_fit_result()
   {
      printf("x0 %f y0 %f R %f pt %f (MeV/c) deg1 %f deg2 %f\n", x0_fit, y0_fit, R_fit, pt_fit, deg1_fit, deg2_fit);
   };
   void draw()
   {

      for (int ihit=0; ihit<nhits; ihit++) {
         TMarker* m = new TMarker(xhits[ihit], yhits[ihit], 8);
         m->Draw();
      }

      draw_fit_circle();
      draw_center_point();
   };
   void draw_center_point()
   {
      TMarker* m = new TMarker(x0_fit, y0_fit, 8);
      m->SetMarkerColor(line_color);
      m->Draw();
   };
   void draw_canvas()
   {
      TH2F*  h2 = new TH2F("fname","", 100, -100, 100, 100, -100, 100);
      h2->SetStats(0);
      h2->Draw();

      draw_radius();
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
   if (drad<0) drad += 2.0*TMath::Pi();
   double L = if_pz/(3.0*B); // cm
   printf("estimate_z2 if_pz %f (MeV/c) L %f cm\n", if_pz, L);
   return z1 + L * drad;
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
   struct Circle circ3; // both-layer
   circ1.set_line_color(kRed);
   circ2.set_line_color(kBlue);
   circ3.set_line_color(kMagenta);

   FILE* fpout = fopen("debug.txt","w");
   char title[12];
   //for (int iev=0; iev<2000; iev++) {
   for (int iev=2; iev<3; iev++) {

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

      circ1.fit();
      circ2.fit();
      circ1.print_fit_result();
      circ2.print_fit_result();

      struct TwoCircle tc;
      tc.calc(circ1, circ2);
      tc.print();

      double if_pa = 104.0; // MeV/c
      double if_pz = TMath::Sqrt(if_pa*if_pa - circ1.pt_fit*circ1.pt_fit);
      double z1_exp = estimate_z1(tc.dr);
      double z2_exp = estimate_z2(z1_exp, circ1.rad2_fit - circ1.rad1_fit, if_pz);
      printf("--- iev %d z1_exp %f z2_exp %f\n", iev, z1_exp, z2_exp);

      TVector3 mcPos;
      TVector3 mcMom;
      inROOT.getPosMom(0, mcPos, mcMom);
      double mc_z = mcPos.Z();
      double mc_pt = sqrt2(mcMom.X(), mcMom.Y())*1e3; // GeV -> MeV
      double mc_pz = mcMom.Z()*1e3; // GeV -> MeV
      fprintf(stdout, "## iev %5d mc_z %f mc_pt %f mc_pz %f dr %f deg %f\n", iev, mc_z, mc_pt, mc_pz, tc.dr, tc.deg);
      fprintf(fpout, "%5d %f %f %f %f %f\n", iev, mc_z, mc_pt, mc_pz, tc.dr, tc.deg);

      // Shift zpos according to tc.dr and set hits in circ3
      struct Circle circ10;
      struct Circle circ20;
      circ10.copy_hits(circ1);
      circ20.copy_hits(circ2);
      circ10.update_xypos(inROOT.getConfig(), z1_exp, z2_exp);
      circ20.update_xypos(inROOT.getConfig(), z1_exp, z2_exp);

      struct Circle circ3;
      circ3.add_hits(circ10, circ20);
      circ3.fit();

      TCanvas* c1 = new TCanvas("c1","",2000,2000);
      c1->Divide(2,2);
      c1->cd(1); circ1.draw_canvas(); circ1.draw();
      c1->cd(2); circ2.draw_canvas(); circ2.draw();
      c1->cd(3); circ1.draw_canvas(); circ1.draw(); circ2.draw();
      c1->cd(4); circ3.draw_canvas(); circ3.draw();
      c1->Print(Form("pdf/%05d.pdf", iev));

   }
   fclose(fpout);

   return 0;
}
