/*
 *      Author: Artur Waz
 *      Year: 2015
 */


#include <Lidar2D.h>


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE lidar2d
#include <boost/test/unit_test.hpp>



struct UnitTest_Lidar2D {
	UnitTest_Lidar2D(): lidar{&map} {}

	double eps{1e-12};



	Lidar2D lidar;
	Map2D map;
	Point2D pose;
};


BOOST_FIXTURE_TEST_SUITE(LidarSensor, UnitTest_Lidar2D)



BOOST_AUTO_TEST_CASE(SimpleCase){
	map.lineSegments = std::vector<LineSegment2D>{
		LineSegment2D{Point2D{-2,-3},Point2D{68,84}}
	};
	pose = Point2D{12,45};

	double results[361] // generated from matlab/octave
				   { 24.6206896551724092603308235993608832359314, 24.9751993973023793671472958521917462348938, 25.3479013718564019086443295236676931381226, 25.7398548188051634610928886104375123977661, 26.1522114935763987375594297191128134727478, 26.5862255880537823315989953698590397834778, 27.0432649737439234627345285844057798385620, 27.5248239763629349852180894231423735618591, 28.0325379298766996782887872541323304176331, 28.5681998050858041438004875089973211288452,
				   29.1337792651871083648984495084732770919800, 29.7314445709264916217762220185250043869019, 30.3635878442625468665028165560215711593628, 31.0328543061087103183126600924879312515259, 31.7421762361833543764078058302402496337891, 32.4948125684123141354575636796653270721436, 33.2943952430563143707331619225442409515381, 34.1449836991643209671565273310989141464233, 35.0511292245624233032685879152268171310425, 36.0179513074998212118771334644407033920288,
				   37.0512286842118356844366644509136676788330, 38.1575084908545534290169598534703254699707, 39.3442378627408686497801681980490684509277, 40.6199235567302565641512046568095684051514, 41.9943268138020542323829431552439928054810, 43.4787028842117280191814643330872058868408, 45.0860976312631578366563189774751663208008, 46.8317177376171542846350348554551601409912, 48.7333967409046948660034104250371456146240, 50.8121871423160769154492300003767013549805,
				   53.0931202553704224555986002087593078613281, 55.6061919803562574315947131253778934478760, 58.3876569592732792557399079669266939163208, 61.4817498500190851018487592227756977081299, 64.9430077504292029288990306667983531951904, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 49.4598340059164414128645148593932390213013, 47.4970360136577269827284908387809991836548, 45.6974662943342053722517448477447032928467, 44.0422088951965804426436079666018486022949, 42.5151713784442790711182169616222381591797, 41.1025774115498876426499919034540653228760,
				   39.7925649969732546651357552036643028259277, 38.5748655434454263968291343189775943756104, 37.4405454178073853199748555198311805725098, 36.3817962326017720897652907297015190124512, 35.3917634749629428370099049061536788940430, 34.4644055411224030649464111775159835815430, 33.5943770640964345375323318876326084136963, 32.7769317872704064598110562656074762344360, 32.0078412680578736626557656563818454742432, 31.2833264818183884869995381450280547142029,
				   30.6000000000000014210854715202003717422485, 29.9548168837880659509664837969467043876648, 29.3450327988252048783124337205663323402405, 28.7681681424551598524885775987058877944946, 28.2219772007416302983529021730646491050720, 27.7044215319383475559789076214656233787537, 27.2136469164810392840081476606428623199463, 26.7479633288042215610857965657487511634827, 26.3058274793644528699587681330740451812744, 25.8858275508171047363248362671583890914917,
				   25.4866698139256797617235861252993345260620, 25.1071668592844439160671754507347941398621, 24.7462272224918393703774199821054935455322, 24.4028462147541347349033458158373832702637, 24.0760977993879095038209925405681133270264, 23.7651273784186400916951242834329605102539, 23.4691453733038066786775743821635842323303, 23.1874215004460317857137852115556597709656, 22.9192796561635674379431293345987796783447, 22.6640933376087900796846952289342880249023,
				   22.4212815361420965132310811895877122879028, 22.1903050481780432789946644334122538566589, 21.9706631557731526527277310378849506378174, 21.7618906354234304956207779468968510627747, 21.5635550588503797087014390854164958000183, 21.3752543541193453791038336930796504020691, 21.1966145993662316016070690238848328590393, 21.0272880248052729257324244827032089233398, 20.8669512016318705605044669937342405319214, 20.7153033989879773457687406335026025772095,
				   20.5720650923790415731673419941216707229614, 20.4369766088695428152277600020170211791992, 20.3097968960790282721973198931664228439331, 20.1903024034853260104682703968137502670288, 20.0782860658469530790171120315790176391602, 19.9735563797059150203949684510007500648499, 19.8759365649470112202834570780396461486816, 19.7852638042886326275038300082087516784668, 19.7013885543774804887107165995985269546509, 19.6241739228702485320354753639549016952515,
				   19.5534951065198114861232170369476079940796, 19.4892388858521030670090112835168838500977, 19.4313031725314573350260616280138492584229, 19.3795966059742745812854991527274250984192, 19.3340381961900718010838318150490522384644, 19.2945570102112711197150929365307092666626, 19.2610918998234375010270014172419905662537, 19.2335912686310841479553346289321780204773, 19.2120128767943683101293572690337896347046, 19.1963236820530482873436994850635528564453,
				   19.1864997159193038100966077763587236404419, 19.1825259941733463620039401575922966003418, 19.1843964610386024105537217110395431518555, 19.1921139666488542729894106741994619369507, 19.2056902776512501418437750544399023056030, 19.2251461210185503603042889153584837913513, 19.2505112613746014460502919973805546760559, 19.2818246123708192385493020992726087570190, 19.3191343828913986158113402780145406723022, 19.3624982591134475740091147599741816520691,
				   19.4119836237087177721605257829651236534119, 19.4676678137482994657148083206266164779663, 19.5296384191648293437992833787575364112854, 19.5979936239410790221882052719593048095703, 19.6728425925341880997621046844869852066040, 19.7543059044148883174329967005178332328796, 19.8425160400064335419756389455869793891907, 19.9376179217538052057534514460712671279907, 20.0397695145467764632485341280698776245117, 20.1491424902675824171183194266632199287415,
				   20.2659229618435929864972422365099191665649, 20.3903122928674740421683964086696505546570, 20.5225279896120049727414880180731415748596, 20.6628046831274403416500717867165803909302, 20.8113952100805086331547499867156147956848, 20.9685718020927041038703464437276124954224, 21.1346273945823242002006736584007740020752, 21.3098770675311683930885919835418462753296, 21.4946596322131711076508508995175361633301, 21.6893393797679934209554630797356367111206,
				   21.8943080096170135107058740686625242233276, 22.1099867581477234068643156206235289573669, 22.3368287508862550794219714589416980743408, 22.5753216046027880281599209411069750785828, 22.8259903095236218462105171056464314460754, 23.0894004261487850726553006097674369812012, 23.3661616362014612491293519269675016403198, 23.6569316930981123903166007949039340019226, 23.9624208241781602168885001447051763534546, 24.2833966449650873187238175887614488601685,
				   24.6206896551724128130445023998618125915527 };

	auto toScietific = [](double const &distance, double const &result) -> std::string { std::stringstream s; s << std::scientific << std::abs(distance-result); return s.str(); };

	for (int i = 0; i <= 360; ++i) {
		double const distance{lidar.measure((i/180.)*lidar.pi,pose)};
		BOOST_REQUIRE_MESSAGE(std::abs(distance-results[i]) <= eps,
				std::string("Problem with angle: ")+std::to_string(i)+
				std::string(". Should be: "+std::to_string(results[i])+
				std::string(", but is: ")+std::to_string(distance))+
				std::string(". Difference: ")+toScietific(distance,results[i]));
	}
}


BOOST_AUTO_TEST_CASE(LidarPlacedInLineSegment){
	map.lineSegments = std::vector<LineSegment2D>{
		LineSegment2D{Point2D{-3,-3},Point2D{68,68}}
	};
	pose = Point2D{-3,-3};

	/*double results[361] // generated from matlab/octave
				   ;*/

	auto toScietific = [](double const &distance, double const &result) -> std::string { std::stringstream s; s << std::scientific << std::abs(distance-result); return s.str(); };

	for (int i = 0; i <= 360; ++i) {
		double const distance{lidar.measure((i/180.)*lidar.pi,pose)};
		BOOST_REQUIRE_MESSAGE(std::abs(distance) <= eps,
				std::string("Problem with angle: ")+std::to_string(i)+
				std::string(". Should be: "+std::to_string(.0)+
				std::string(", but is: ")+std::to_string(distance))+
				std::string(". Difference: ")+toScietific(distance,.0));
	}
}


BOOST_AUTO_TEST_CASE(LidarPlacedInLine){
	map.lineSegments = std::vector<LineSegment2D>{
		LineSegment2D{Point2D{-3,-3},Point2D{68,68}}
	};
	pose = Point2D{100,100};

	double results[361] // generated from matlab/octave
				   { 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 45.25483399593903754976, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300, 1.0e+300,
				   1.0e+300 };


	auto toScietific = [](double const &distance, double const &result) -> std::string { std::stringstream s; s << std::scientific << std::abs(distance-result); return s.str(); };

	for (int i = 0; i <= 360; ++i) {
		double const distance{lidar.measure((i/180.)*lidar.pi,pose)};
		BOOST_REQUIRE_MESSAGE(std::abs(distance-results[i]) <= eps,
				std::string("Problem with angle: ")+std::to_string(i)+
				std::string(". Should be: "+std::to_string(results[i])+
				std::string(", but is: ")+std::to_string(distance))+
				std::string(". Difference: ")+toScietific(distance,results[i]));
	}
}



BOOST_AUTO_TEST_SUITE_END()

