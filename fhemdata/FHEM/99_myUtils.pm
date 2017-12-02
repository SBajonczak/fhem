##############################################
# $Id: myUtilsTemplate.pm 7570 2015-01-14 18:31:44Z rudolfkoenig $
#
# Save this file as 99_myUtils.pm, and create your own functions in the new
# file. They are then available in every Perl expression.

package main;

use strict;
use warnings;
use POSIX;

sub
myUtils_Initialize($$)
{
  my ($hash) = @_;
}

sub CalenadarOutput()
{

my $viewName = "FamilienCalView";
my $htmlOutput="";
my $amount = ReadingsVal($viewName,"c-term", 0);
my $temp = "";
for(my $i= 1;$i<=$amount;$i++){

   my $daysLeft =  ReadingsVal($viewName ,"t_".sprintf('%03d',$i)."_daysleftLong", 0);
   my $summary  =  ReadingsVal($viewName ,"t_".sprintf('%03d',$i)."_summary", 0);
   $temp.= $daysLeft." ".$summary."<br/>";
	
}
if ($temp ne ""){
$htmlOutput.="<div><table><td><td><h1><i class='fa fa-calendar' aria-hidden='true'></i></h1></td><td  align='left' style='padding-left:10px'>".$temp."</td></tr></table></div>";
}

fhem "set FamlienKalenderDummy ".$htmlOutput;

}


sub CheckOpenedWindowAndGenerateMessage()
{
  my $list  ="Arbeitszimmer_links,Arbeitszimmer_rechts,Badezimmer,Balkontuer,Dachfenster_Garten,Dachfenster_Strasse,Dachgeschoss_Seite,GaesteWC,HEIZRAUM,Haustuer,Kinderzimmer_Links,Kinderzimmer_rechts,Kuechen_Fenster,Wohnzimmer_Seitenfenster";
  my @aliases;
  my $text = undef;

  foreach my $dev (split(",",$list))
  {

    if (Value($dev) eq "opened")
    {
      my $alias = AttrVal($dev,"alias",$dev);
      push @aliases,$alias;
    }
  }
  $text = "<h1 style='color:green'>Alle Fenster geschlossen! <i class='fa fa-smile-o' aria-hidden='true'></i></h1>";
  # Build Warning text
  if (@aliases > 0)
  {
    $text = "<h1 style='color:red'>ACHTUNG!</h1> <b>".$aliases[0]."</b>";
    if (@aliases > 1)
    {
      for (my $i = 1; $i < @aliases; $i++)
      {
        $text .= " und " if ($i == @aliases - 1);
        $text .= ", " if ($i < @aliases - 1);
        $text .= "<b>".$aliases[$i]."</b>";
        $text .= " sind" if ($i == @aliases - 1);
      }
    }
    $text .= " ist" if (@aliases == 1);
    $text .= " noch geöffnet. <i class='fa fa-frown-o' aria-hidden='true'></i>" if (@aliases > 0);
  }
  fhem "set fensterStatusMsg ".$text;
}




1;
