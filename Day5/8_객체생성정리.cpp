// 8_객체생성정리

// C++에서 객체를 만드는 방법

// 1. 외부에서 생성			: new Rect
// 2. static 멤버 함수 사용	: Rect::Create()
//							  // 싱글톤, Flyweight
//							  // 함수 인자로 생성함수 전달 가능
//							  // (참고: Effective Java에서 소개, Java에서도 사용함)
// 3. 견본에 의한 생성			: p->Clone()
// 4. Factory의 도입			: factory->Create()
// 5. Factory method		: virtual Create() override

// GoF's 패턴 23개
// - 생성 패턴 5개	: Singleton, Prototype, Abstract factory, Factory method, Builder
// - 행위 패턴 11개
// - 구조 패턴 7개
