# %%
import numpy as np

from collections import namedtuple
from timeit import timeit

from uniquetol import uniquetol

#%%
testArr = np.array(
    [180.5664822422, -205.41562902219766, -137.46006419434175, 117.83830520051663, -51.020627993925345, -108.77925415963594, -98.92493482144134, -270.5373125221961, -199.25903889951624, 24.106637623562428, -35.69062384307369, 38.36133149749162, 7.349975560044633, -160.27353409523678, -205.41562855632824, -74.40653798118524, -235.8906122965523, 14.280752546899, 170.32571778056135, 84.29615833773335, -205.4156287672579, -174.75004901977073, -44.32407382386476, 99.81295625092869, 84.01836505188882, -236.58016395368338, -133.88578238468148, 21.25132663591139, 143.67787347904635, -160.27353320071836, -137.46006386836333, -35.690624137931096, -201.62956804352064, -88.93630940459278, 24.106637217015436, -174.75004914510228, 48.456950535482754, 143.67787450721943, 166.31039126242487, 180.5664823555178, 34.70461111281012, 231.75502920666682, -235.89061191514585, 231.75502995736926, -3.666509251390369, -89.84780641591732, 14.28075161361321, 14.280752363919895, 26.590478791121512, -3.6665103319767454, -145.84588844842395, -145.84588837341732, 131.8889660930086, 32.89215420906143, 34.70461081296861, 178.99681626759758, 94.70808872634659, -270.5373135847109, -11.969271564419062, -145.8458880601675, 34.7046099416332, 183.8342816734689, 166.3103906764077, 131.88896635951167, -229.97754192195052, 231.75503007620972, -236.58016375853018, 183.8342825086968, 141.87839820999184, -235.89061277250968, 132.59753373757698, -108.77925418223651, -132.3967014292477, 14.28075322156907, -284.7191398611967, -145.84588734510191, -225.82235898454988, 24.10663838734996, -108.77925234563493, -166.11640049757602, -31.693764353772067, -160.31459097294305, -11.969272156495837, 127.77050422111448, 94.70808887252548, 99.8129551694144, -74.4065372800527, 14.280751651646154, -205.41562857989825, -11.969271538456434, 170.32571920503193, 11.222143027591427, -199.25903896808032, -235.89061197983082, -137.46006525412537, 48.45695070346296, -23.268890486973508, -201.6295669008092, 117.83830552070279, -235.31390372508554, -74.40653634475807, -236.58016292535532, -131.7817660484831, -143.8213803997485, 88.75495215461571, 170.31293262353336, -145.8458879807499, -166.1164014417964, -9.546941789453381, -92.86098953928499, 117.83830484930587, 88.75495228948388, -51.02062768249469, 21.251326785463316, -75.18391867516272, -145.84588744078724, 34.704610345765396, -39.582421945353815, 48.456949738387074, -3.666511000700661, 170.32571911354472, -166.11640062872272, 77.2525974896292, -8.312738870205482, -75.18391866273198, 149.75887706978108, 48.45694994138311, -9.546941037769763, -77.99313591141474, 24.106637841334837, 32.892154797125514, 154.87136876826094, -98.92493538714173, -188.8429993617005, -205.41562888288195, 183.83428161705274, -229.97754122588177, -235.8906117740372, -235.89061184944336, -143.82137911822255, 21.25132761051629, -258.3473307097019, -235.31390451144145, -160.31459075748512, 24.106638819810442, 149.7588761994372, 231.75503004937983, -205.4156289784763, -205.41562864014867, 166.31039132359354, -98.92493577335891, 38.36133156846067, 84.01836444191333, -88.93630906205325, -31.693762473790798, 32.89215448478927, -98.92493496592161, 183.8342813974272, -98.92493474198415, -241.32977841208492, -132.86509183197805, -88.93630924846602, 178.9968155391682, 32.89215385982676, -270.5373128645731, -31.693762817636657, -148.96192210867255, -241.79791415053546, -236.58016412684944, 154.8713701577064, -270.5373132148728, -166.11640020508736, -258.3473306291511, -69.9479710071989, -3.666509904561906, -241.32977787589394, -259.28257739946514, 24.106638746282396, -98.92493623224728, -176.6702932228749, -55.848481641148176, 99.81295669318668, 170.3257179980955, -148.96192217290357, -160.3145905752169, -235.8906113037908, 32.892154490274415, -124.47644939581114, -199.25903865411084, -92.86098941482027, -74.40653683088034, 170.31293119143734, 21.25132753575529, -188.84299938477446, -35.69062352437625, -88.93630892834045, -160.27353398310257, -75.18391901480332, -39.58242291717712, -94.92513209501523, -89.8478060115597, -236.58016338088814, -98.92493424810593, -77.99313611854944, -51.02062755329588, -89.84780507164474, 170.3257181343631, 14.280752125718898, -77.99313619990296, -108.77925245359016, 170.3129312365556, -108.7792531965926, 149.75887800811762, -43.37101655948333, -270.53731246738977, 14.280751457647384, -94.92513268188885, 26.590479496558714, 131.88896491162117, 94.7080903277924, -92.86098791269463, 132.59753265521346, 34.70460930355239, -2.3609532952225423, -88.93631029685885, -89.84780550780556, 14.280752093495344, 94.7080887509971, -259.2825765711832, 99.81295573248494, 34.70461051895926, -43.37101695156991, -3.6665097252741816, -31.693763610594438, 14.280752125769986, -108.77925260616236, -235.31390353729347, 180.56648267584077, 34.704609853162744, -145.84588790615257, 228.69544368319688, 228.6954428866364, -37.30474572603776, -148.96192089408447, 84.01836565551193, 180.56648369657557, -199.25903825901605, 170.32571849924463, -13.485936006164255, -236.5801629756885, -88.93631043654939, -284.7191387480962, -31.693763997493875, -98.09063241198137, -201.62956763449492, -137.46006393472658, -35.69062280822734, 228.69544339476641, -23.26888882996419, -94.10689131743216, -6.834660328120918, -284.71913957000527, 132.5975333888099, 149.75887742359546, 84.01836535525955, -3.6665101253426693, -176.6702919599429, -51.02062738451168, -92.86098823634147, 149.7588779518309, -75.18391814080506, -236.58016377656236, -74.40653695574677, 141.87839788339022, -229.97754205852468, -160.3145914188386, -92.86098956577679, 117.83830492351288, 154.8713686206763, 48.456950747918526, -284.71913911867654, -148.96192167982167, -235.31390471157908, -11.969272719932555, -201.62956748071065, -44.32407392642975, 21.251328100652447, -174.7500504345443, 32.892155103278014, -75.18391827292558, -143.82138009285012, 144.49747948725064, -143.82137973942355, -229.97754130805288, 21.251328353164297, -170.4379416838887, -13.485935003059208, -98.92493443365585, -69.94796911602444, 88.75495112391769, -77.9931345301213, -23.26888940111442, 170.32571765289612, -137.46006440202936, 88.75495245543159, -284.71913917960165, -174.7500496595906, -166.11640087930982, -148.961922179542, 143.67787472574278, -51.02062800032391, -98.09063188339054, -124.47644968371803, 14.280752350603533, -94.10689158965364, 141.87839801996358, -188.84299959402523, -270.53731226240984, -137.46006516839952, 131.88896562663214, -13.485934722264712, -92.86098925945188, 48.456949833079506, -170.43794244595665, -143.82137981930373, 149.7588769950933, 88.75495227553164, -88.9363098270736, -235.31390403194396, -131.78176617181163, -241.3297786863952, -74.40653615407412, 94.70808884994582, -143.82137902772777, -160.3145900949995, -284.719138075794, 170.32571738338345, 88.75495245037312, -23.268889380334734, -98.9249352701704, -236.5801628518233, 84.0183650979125, -13.485935587669928, -241.79791434356068, 34.70461016392089, -3.6665097023777413, 84.01836448976468, 178.9968157896777, -23.268889471201792, 14.280752369699245, -236.5801627694828, -94.10689075874161, -23.26888988421997, -23.26889025406304, 143.67787399280522, -31.693763734554434, -51.0206282808827, 149.75887686079736, 88.75495221279459, 88.75495204509555, -89.84780639695829, -131.94123269773078, 24.10663866552711, -55.848482003587435, -145.84588699445655, -145.84588821035095, -31.693762721289012, -94.925131670902, -3.6665096887641764, 11.242105807967716, -77.9931350159835, -205.41562897681658, -176.6702934674316, 21.251327273843714, -43.371017250880755, -11.969271220603604, -75.18391954712266, 24.10663787485229, -235.89061147182528, -44.32407399832394, -270.53731344817544, 99.81295496973581, 99.8129563055593, -270.5373124071189, -92.86098831200715, -270.5373124434871, 99.81295526281721, -6.8346604703113, -31.693763740451367, -258.3473304660023, -35.69062428170508, 132.5975337323454, 183.83428281047458, -199.25903811961808, -188.84299988246525, -236.5801629219892, 132.59753289651294, 38.36133182716328, 132.597532700911, 170.31293290935804, -96.79973299875289, -137.4600653475179, -35.690624698636846, 26.590479048760567, -94.10689164449897, 132.597533500123, 24.106636900042098, 26.590478881999204, -160.31459124823914, -88.93630909978789, -92.86098790144031, 88.75495227258058, -3.6665107586238936, -133.88578164758002, 178.99681620331555, 7.349974458684432, -284.7191384412013, 131.88896505208115, -108.91085773689086, -92.8609892238653, -108.91085773071102, -160.31459102941778, -148.96192105517719, -176.67029206426346, -145.8458875287372, -241.32977755688032, 117.83830588630948, -229.97754132846063, -51.020628435431746, 84.01836529749107, 84.29615822866566, -35.69062309449139, -88.93630936668637, -145.84588742130597, 117.83830454606304, 180.56648342632047, 132.59753311497056, -13.48593627318832, -88.93630932262846, -284.71913910380556, -108.77925407979143, -284.7191390175765, -6.8346618258401675, 143.6778737398682, 24.106637911605375, -98.09063256136034, 143.67787291580808, 166.3103915138572, -77.9931347810361, 183.83428273018163, -69.94797028357442, -225.82235815843165, 154.87136920724316, -31.693764255697893, -131.94123279424315, 231.75502980283002, -9.546940408824534, -2.3609525830198317, -74.40653690437476, -148.96192156639245, -108.7792526670544, 180.56648328241644, 170.31293117563078, 11.22214344130702, -174.75004969187253, -3.666510920496762, 166.31039055172502, 149.7588774068209, -199.25903881658542, 170.3129327992701, -31.69376280707999, -137.46006429663635, -108.77925250873808, 131.88896558899538, -37.30474439450691, -98.09063246096325, -31.693762479429996, -15.796952651163755, -137.46006474479856, 14.280753025372041, -284.7191395627346, 38.36133188531345, 84.01836504267277, -108.91085766879537, -235.8906128439085, -270.5373119656402, -124.47645067084721, -37.3047455736198, -69.9479691939723, 144.4974789810723, 38.361332144986164, -143.82137941705793, -145.84588748307473, 11.242106502867916, -229.9775422355084, 94.70809028517714, -241.3297792742023, -174.75004935536026, 117.83830499418853, -88.9363089636593, -270.53731222555905, -89.84780496743794, 149.75887802899402, -98.09063276737291, 178.99681683643922, 154.87136889698792, 170.3257181606554, -199.25903851584806, 99.81295506139644, 154.87136998983027, -75.18391944554511, 223.83912075818392, -89.84780471655671, -94.10689169595668, -208.5665301681666, -137.4600646780177, 99.81295598026988, -241.32977820956154, -176.670292764273, 84.2961576512481, -258.3473303574032, 231.75502960852668, -137.46006512385193, -6.834661228443029, -51.02062919538486, 131.8889665428705, -199.2590375547239, -176.67029306661635, 166.31039068930883, -133.88578261596635, -166.11640116742672, -132.86509190300526, -77.99313566435383, -199.2590383898128, -31.69376286783218, -89.84780522512807, -201.6295676037979, 38.361330852913326, -205.41562870858385, 231.75502895607738, -241.7979142673598, -51.02062869827818, -174.75005013339901, -23.26889017340144, 7.34997575716558, -124.47645104858277, 26.59047847239977, 94.7080884933836, -98.09063301286382, -2.3609520341266004, 26.59047942529737, -284.7191386308504, 231.75502926593063, -2.360951885957095, -74.40653666693433, -74.4065364930736, -133.8857819034966, -98.92493512604753, -88.9363092832405, -241.79791393341765, 94.70809028515237, -35.69062343586222, 170.3257176799306, -241.32977940211435, -23.268890187928132, -51.02062804880878, -98.92493620469652, 24.106638062458945, -236.58016283098658, -43.371017436368504, -23.268889510247664, 117.8383052815372, 231.75502907515246, -8.312739670738436, -143.82138083681363, 7.349973935661742, 144.4974788393732, -160.31459060781754, -201.62956763461355, 183.8342826884928, -88.93631047204002, 228.69544284479846, -132.86509195061888, -13.485935133629582, -3.666510285935208, -44.324073556879895, -160.27353264430593, -11.969271428311323, 141.87839830778617, -143.82138006827898, -37.30474573275205, 77.25259722379812, -148.96192159333393, -241.3297793305004, 21.251327615206556, 170.31293171432654, -35.69062325860549, -199.2590375953753, -94.92513256927018, -89.8478045527712, -258.3473308632185, 154.871369485589, -11.96927272543186, -13.48593539430067, -3.666510133582635, -199.25903772726275, 94.7080902258452, 143.67787375279178, 154.87137004272066, -270.53731362799533, -44.32407393563892, 170.32571913109584, -69.94796995339156, 144.49747985432566, -51.02062865053751, -37.30474520282724, -2.3609520897462764, 88.75495145098837, 84.01836593760294, 144.49747885792644, -143.8213791379271, 117.83830559077727, -69.94796931659859, 132.597532574195, 178.99681532773553, -236.5801637142804, -51.02062821672695, -108.77925411156687, 166.3103905939097, 132.59753278946502, -77.99313617351383, -205.41562981223325, -236.58016233519893, -143.82137972823685, -43.371016514040285, 26.59047946850852, -166.1164013465915, -284.71913828593, -3.6665098629295776, 38.36133121361211, 183.83428228431745, -98.92493498263752, -160.31459096972057, 117.83830579764756, 166.31039208883712, -89.84780527422875, -166.11640059854884, -108.77925295763775, 48.456949990601, -75.18391978881193, 38.361332120231076, -89.84780453341781, -39.58242331629169, -108.91085671190187, -96.79973316343352, -148.96192117407014, 144.4974806367167, -137.46006385601194, -35.690624251037335, 131.88896563390915, 183.5309896648829, -225.82235850943627, -31.693763988304145, 94.70808844853566, 170.3257184776889, -160.31459044578867, -77.99313572307284, 143.67787375996258, -23.26889068319544, 231.75503056133024, 166.31039126200656, 131.88896582685962, -133.8857820975443, 170.32571901639292, -132.3967015983542, 144.4974795568466, 183.83428159165484, 99.81295561767554, 99.81295582879345, 131.88896578829826, 166.3103911990392, -75.85677437069745, 183.83428303715806, -241.79791373849844, -51.02062862848735, -35.69062469404232, 7.349975655284199, -75.85677511545033, -188.84299959934435, 127.77050503505465, 143.67787345202584, 84.01836574556042, 34.70460987731798, -148.9619221170524, 132.59753323297716, -9.546941887890133, 143.6778732803688, -98.09063200732568, -166.11640012798657, 183.5309891594998, 149.75887801901982, -145.84588728510852, 166.31039035186262, -39.58242301796558, 117.83830417669898, 38.36133084343793, 94.70809036678165, -235.89061094191902, -166.1164010736417, -44.32407491447321, 48.456950621559066, 94.70809020641107, 131.88896606256162, 26.59048014425447, 14.280751963253106, 7.3499750978508205, -35.69062343106186, -205.41562982897997, -89.84780568355329, -98.9249344759957, -44.324074048800114, 170.31293193550704, -160.31459103264243, -94.92513255342452, 84.01836562296047, -160.3145897764413, -284.7191390379055, -9.546940878844033, -92.86098896790158]
)

# %%
(u, ix, inv, cts) = uniquetol(
    testArr,
    return_indices=True, return_inverse=True, return_counts=True,
)
spaces = np.diff(u)
Vars = namedtuple('Vars', 'testArr u ix inv cts spaces')
variables = Vars(testArr, u, ix, inv, cts, spaces)

# %%
# timeit(lambda: uniquetol(testArr), number = 10000)