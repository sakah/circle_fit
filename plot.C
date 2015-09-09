{
   TTree t;
   t.SetMarkerStyle(20);
   t.ReadFile("debug.txt","iev/I:num:dr/D:deg:zhit:zfit:pthit:ptfit:pzhit:pzfit:chi2");
}
