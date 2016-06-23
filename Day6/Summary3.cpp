/*
행위 패턴 11개

복합 객체(list, vector, popupmenu 등)의 요소에 대한 패턴 2개
  - Iterator	: 컨테이너의 내부 구조에 상관 없이 동일하게 열거
  - Visitor		:               "              동일한 방식으로 요소 사용

이벤트를 여러 곳에 보내는 패턴 2개
  - Observer	: 이벤트를 등록된 모든 객체에 전달 (plug-in 만들기)
  - Chain of responsibility	: 발생된 이벤트를 객체에 전달, 처리되지 않으면 다음 객체로 넘김
							  아이폰의 Responder chain

변하는 것을 분리하는 패턴
  - Template method
  - Strategy
  - State

명령의 캡슐화
  - Command

관계가 복잡한 객체(협력자들) 사이의 중간층
  - Mediator

객체의 상태를 저장했다가 원할 때 복구
  - Memento

컴파일러나 파서 만들 때 사용 (수업 내용 외)
  - Interpreter



<객체지향의 원칙>
  - OCP (Open Close Principle) : 기능이 추가되어도 기존 코드는 수정되면 안된다
  - DIP (Dependency Inversion Principle)
  - LSP (Liskov Substitution Principle)
  - SRP ()
  - ISP (Interface Surrogate Principle) 인터페이스는 격리하는 것이 좋다



<설계 기법과 관련된 용어>
  - 아키텍쳐	: 언어 자체를 설계하거나 OS 자체를 설계할 때 사용하는 기법들
  - 패턴		: 언어에 상관 없이 객체지향 S/W 만들 때 사용하는 설계 기술
  - Idioms	: 특정 언어에 관련된 디자인 기법


<추천 서적>
  - * GoF's 디자인 패턴		: 이미 있는 기법을 정리하고 용어를 정리.
  - 알기쉬운 디자인 패턴 (C++)	: 패턴의 철학 및 적용방법
  - Pattern Oriented System Architecture
*/