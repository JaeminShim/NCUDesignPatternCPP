/*
<객체지향 설계의 핵심 part1>

1. 공통성과 가변성의 분리
  : 변하지 않는 흐름에서 변하는 코드를 찾아서 분리한다.

  1) 변하는 것을 가상함수로
	- Template method	: 알고리즘이 변함
	- Factory method	: 객체 생성 방식이 변함

  2) 변하는 것을 다른 클래스로
	A. 인터페이스를 사용해서 변하는 정책 클래스 교체
	  - Strategy
	  - State
	  - Builder

	B. 템플릿 인자를 사용한 정책 클래스 교체
	  - Policy base 단위 전략 (in C++)

생성 패턴 5가지: Singleton, Builder, Factory method, Abstract factory, Prototype
*/