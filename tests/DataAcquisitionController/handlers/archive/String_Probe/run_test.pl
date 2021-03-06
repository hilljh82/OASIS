eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id: run_test.pl 2115 2012-01-13 13:57:53Z dfeiock $
# -*- perl -*-

use lib "$ENV{'ACE_ROOT'}/bin";
use PerlACE::Run_Test;

$OASIS_ROOT = "$ENV{'OASIS_ROOT'}";

# Start the DAC
print "*** Starting the DAC...\n";
$the_DAC_options = "-ORBEndpoint iiop://localhost:20000 --name=String_Probe -c String_Probe.conf --database=String_Probe.db";
$the_DAC = new PerlACE::Process ("$OASIS_ROOT/bin/oasis_dac", $the_DAC_options);
$the_DAC->Spawn ();

print "*** Sleeping for 2 seconds...\n";
sleep (2);

# Run the smoke test.
print "*** Starting the test application...\n";
$the_SmokeTest_opts = "-ORBInitRef DAC=corbaloc:iiop:localhost:20000/SmokeTest";
$the_SmokeTest = new PerlACE::Process ("OASIS_DAC_Archive_Service_String_Probe_Test", $the_SmokeTest_opts);
$the_SmokeTest->Spawn ();

sleep (15);

# Kill the application
$the_SmokeTest->Kill ();
$the_SmokeTest->TimedWait (1);

# Kill the DAC
$the_DAC->Kill ();
$the_DAC->TimedWait (1);

exit 0;
