v.4.4.5
-------------
### fixed
1. Rebuild with Xcode 11.2.1
Storyboards containing a UITextView will cause the app to crash on operating system versions earlier than iOS 13.2 and tvOS 13.2 if compiled with Xcode 11.2. (56808566)
https://forums.developer.apple.com/thread/125287
https://developer.apple.com/documentation/xcode_release_notes/xcode_11_2_1_release_notes

v.4.4.4
-------------
### fixed
1. iOS UIWebView -> WKWebView 교체

v.4.4.3
-------------
### fixed
1. iOS Moot COPPA 대응

v.4.4.2
-------------
### fixed
1. iOS 13 대응

v.4.4.1
-------------
### fixed
1. iOS AFNetworking Framework 의존성 제거.
2. iOS ApiGateway Framework 의존성 제거.
3. iOS setChannelCode 설정 오류 수정.
4. iOS App Bundle Preferred Localization 기준으로 채널 설정되게 수정.
5. Android 채널 변경 시에 배너 변경되지 않는 이슈 수정

v.4.3.1
-------------
### fixed
1. iOS OpenSSL Framework 의존성 제거.

v.4.3.0
-------------
### fixed
1. 안드로이드 Q 버전 대응 (Android)
2. 간헐적으로 발생하는 Major 버그 수정 

v.4.2.2
-------------
### fixed
1. Unity 백그라운드 화면 터치 이슈 수정 (iOS)
2. 홈 정사각형 배너 비율 수정 (Android)

v.4.2.1
-------------
### updated
1. PLUG 시작시 특정 메뉴를 선택할 수 있도록 하는 기능 추가

### fixed
1. iPad UI 버그 수정( iOS )
2. 게시글 바로가기 Interface 버그 수정
3. 기타 알려진 버그 수정

v.4.2.0
-------------
### updated
1.  PLUG 최적화
2.  Live 제거

v.4.1.1
-------------
### fixed
1. 위젯터치 오류 수정 ( iOS )

v.4.1.0
-------------
### fixed
1. PLUG 배너에서 "외부링크" 항목 추가 (외부 브라우져나 마켓으로 이동할수 있는 링크 입력가능)
2. 기타 알려진 버그 수정

v.4.0.4
-------------
### fixed
1. 안드로이드에서 PLUG화면의 잔상이 남으면서 터치 불가능

v.4.0.3
-------------
### updated
1. Fixed iPhone 5 Crash 
2. 게시글 삭제 오류 수정 (Android)

v.4.0.2
-------------
### updated
1. iOS에서 Global 만 설정하는 경우 크래시 발생 수정. 

v.4.0.1
-------------
### fixed
1. [navercafesdk-2071] 인터넷진흥원 퍼미션 법규 위반 관련 수정 요청

v.4.0.0
-------------
### updated
1. Global Moot 연동 

v.3.3.2
-------------
### fixed
1. initGlobal API 채널 id 설정 이슈 수정  (Android)
2. setChannelCode API 채널 Code 설정 이슈 수정 (Android)

v.3.3.1
-------------
### updated
1. showWidgetWhenUnloadSDK 를 사용할 경우 최소화버튼이 보이지 않도록 수정

### fixed
1. Android P 에서 플러그 화면이 표시되지 않고 투명하게 보이는 현상 수정 (Android)
2. Oreo 이상 버전에서 라이브 촬영 후 저장 시에 터치가 되지 않는 현상 수정 (Android)

v.3.3.0
-------------
### updated
1. 채널변경 on/off 인터페이스 추가
2. KaleidoCore.framework 를 static library  로 변경  (iOS)

### fixed
1. initGlobal API 채널 id 설정 이슈 수정 (안드)
2. Google 로그인 시 join callback 호출 이슈 수정 (안드)
3. 알려진 버그 수정

v.3.2.6
-------------
### updated
1. kaleido 1.4.8 update - android

### fixed
1. Android 8.0 이상일 때 live 중 화면 터치 안되는 이슈 수정 - android
2. 앱 Window 사이즈가 Screen 사이즈랑 맞지 않을 화면 깨지는 문제 수정 - iOS
3. 세로모드 분할형 배너 동영상에서 화면 깨지는 문제 수정 - iOS

v.3.2.5
-------------
### fixed
1. Android 8.0 이상일 때 녹화 중 화면 터치 안되는 이슈 수정

v.3.2.4
-------------
### fixed
1. KaleidoCore.framework 1.4.11 업데이트 (iOS)
2. 라이브중 상대방 위젯에서 live 표시가 잘못 노출되는 이슈 수정 (iOS)
3. 게임 화면 내에서 다른 곳을 터치하거나 화면 드래그 시 플러그 버튼이 사라지는 이슈 수정(안드로이드)
4. 프로필 이미지 클릭시 '인터넷 오류' 팝업 활성화 이슈 수정(안드로이드)

v.3.2.3
-------------
### fixed
1. 플러그 실행 중 게임으로 이벤트 넘어가는 현상 수정 (iOS)
2. 배너 홈에서 메인 배너 영역이 정사각형으로 노출되지 않는 것 수정. (iOS)
3. 배너 홈 서브 배너 노출 사이즈 수정 (안드로이드)
4. startMenu API 동작되지 않은 이슈 수정 (안드로이드)

v.3.2.2
-------------
### fixed
1. 한국어 이외의 언어에서 전체 게시글, 오늘 방문자, 외 X명 번역어 잘못 나오는 이슈 수정

v.3.2.1
-------------
### fixed
1. 특정 단말에서 위젯 버튼 클릭시 크래시 이슈 수정 (아이폰 5c)

v.3.2.0
-------------
### updated
1. 라이브탭 추가
2. 위젯 노출 버튼 변경
3. 라이브 VOD 정렬 기능 추가
4. 좋아요 로직 수정
5. 아이폰 X Safe Area UX 대응 (iOS)
6. 동영상 녹화 시 마이크 옵션 추가(안드로이드)

### fixed
1. 위젯 사라지는 이슈 수정(안드로이드)

v.2.5.5
-------------
### fixed
1. XCode 9 & iPhone 10 대응

v.2.5.4
-------------
### fixed
1. Android 2.5.2 업데이트
2. Android 7.1 이상일 때 접기 버그 수정
3. Android customtab 구글 호환성 수정
4. Android 닫기 텍스트 번역 누락 반영 

v.2.5.2
-------------
### updated
1. iOS 11 대응

v.2.5.1
-------------
### fixed
1. 게시글 바로가기 버그 수정 (안드로이드)

v.2.5.0
-------------
### updated
1. 본분/댓글 번역기능 추가
2. 지원 언어 추가 (브라질, 포르투갈, 이탈리아, 멕시코, 터키, 베트남)
3. 녹화 인터페이스 제공
4. 네이버 로그인 라이브러리 사용시 최초 세팅한 URLScheme, delegate 갱신하도록 변경 (iOS)

v.2.4.6
-------------
### updated
1. 네이버 로그인 SDK의 Bundle 파일에서 .DS_Store 제거 (iOS)
* 관련 이슈 : 윈도우에서 맥으로 원격 빌드시 ITMS-90035 에러

v.2.4.5
-------------
### updated
1. 중국어 번체/간체 오류 수정

v.2.4.4
-------------
### updated
1. 카페 SDK 종료 api 추가.

### fixed
1. 언리얼 게임 쓰레드가 아닌 다른 쓰레드에서 카페 API를 호출하면 크래쉬 발생하는 현상 수정. (안드로이드)

v.2.4.3
-------------
### updated
1. 러이아어 추가
2. 동영상 업로드 시 크기에 따른 압축 품질 변경 로직 추가 (iOS)

v.2.4.2
-------------
### fixed
1. Comment 창이 두번째에는 올라오지 않는 이슈 수정 (안드로이드)

v.2.4.1
-------------
### fixed
1. plug 종료 시에 softkey가 내려가지 않는 이슈 수정 (안드로이드)

v.2.4.0
-------------
### updated
1. Pinned 공지사항 기능 추가
1. 댓글 미리보기 추가
1. WKWebView 적용 (iOS)
1. GLReachability 클래스명 변경 (iOS)
1. 구글 로그인 WebView에서 크롬으로 처리 (안드로이드)
 * 관련 이슈: https://developers.googleblog.com/2016/08/modernizing-oauth-interactions-in-native-apps.html?m=1
1. '스마트폰 앱 접근권한에 대한 정보통신망법 시행령'에 따른 권한 획득시 사용처 고지 (안드로이드)
1. 위젯 스크린샷 버튼 on/off 추가

v.2.3.2
-------------
### fixed
1. 위젯 사라지는 현상 수정
2. 댓글 델리게이트 호출 안되는 현상 수정

v.2.3.1
-------------
### fixed
1. 알려진 버그 수정

v.2.3.0
-------------
### updated
1. 동영상/이미지 모아보기 기능 추가
2. 접기/닫기 기능 개선
3. 위젯 기능 개편
4. 비공개 카페 테스트 가능하도록 변경
5. 스페인어/프랑스어/독일어/인도네시아어 추가
6. 네이버 로그인 관련 API 추가
7. API 변경
    1) 글쓰기 관련 파람 변경
8. API 추가
    1) 위젯 위치 관련 API

### fixed
1. 알려진 이슈 수정

v.2.2.0
-------------
####updated####
1. PLUG에 테마 color 적용 가능
2. PLUG 접기 기능 추가
3. 프로필 사진 업데이트 기능 추가
4. default channel이 device 지정 언어에 따라가도록 변경

v.1.7.0
-------------
####updated
1. 위젯을 통하여 동영상 녹확 기능을 제공합니다.
2. 콜백 API 개선 (투표 완료 콜백을 제공합니다)


v.1.6.0
-------------
####updated
1. 카페 위젯을 지원하여 게임내 어디서든 카페를 이용 할 수 있습니다.


####fixed
1. 게시글 간 이동이 자연스럽게 보이도록 수정


v.1.5.0
-------------
####updated
1. 타인의 프로필을 열람할 수 있습니다.

####fixed
1. 알려진 버그 수정


v.1.4.0
-------------
####updated
1. 프로필 화면에서 작성한 글, 댓글단 글, 좋아요 한 글을 볼 수 있습니다.
2. 카페 SDK 로고를 터치하면 카페 SDK 버전을 확인 할 수 있습니다
3. 글쓰기, 댓글쓰기, 카페가입 리스너를 등록하여 이벤트를 받아 사용할 수 있습니다.

####fixed
1. 알려진 버그 수정


v.1.3.0
-------------
####updated
1. 이미지를 클릭하여 크게 보기를 지원합니다.
2. 특정 게시판으로 바로 이동 할 수 있는 기능을 지원합니다.
3. 투명도 조절바를 on/off 할 수가 있습니다.

####fixed
1. 알려진 버그 수정


v.1.2.0
-------------
####updated
1. 투명도 조절 지원
2. 최신글 목록 보기 지원
3. 게시글 바로가기 기능 지원


####fixed
1. 알려진 버그 수정


v.1.1.0
-------------
###updated
1. 세로형 app 지원. (세로형 UI가 새로 적용되었습니다)
2. 전체 게시판 검색 지원.
3. 카페SDK 시작 및 종료 리스너 추가 
    (setOnSdkStartedListener() 와 setOnSdkStoppedListener() 를 통하여 제공)


v.1.0.0
-------------
 NaverCafeSDK 오픈
