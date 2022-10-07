#include <utility>

namespace ft {

  template<class T1, class T2>

  struct pair {
    typedef	T1 first_type;
    typedef T2 second_type;
 
    first_type first;
    second_type second;
 
    pair( void ) : first(), second()
	{

	}

	template<class U, class V>
	pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
	{

	}

	pair (const first_type& a, const second_type& b) : first(a), second(b)
	{
		
	}

	pair& operator= (const pair& pr)
	{

	}

    template<class U1 = T1, class U2 = T2>
      pair(U1&& x, U2&& y);

    template<class U1, class U2>
      pair(const pair<U1, U2>& p);

    template<class U1, class U2>
      pair(pair<U1, U2>&& p);

 
    pair& operator=(const pair& p);
    template<class U1, class U2>
      pair& operator=(const pair<U1, U2>& p);
    pair& operator=(pair&& p) noexcept(/* see description */);
    template<class U1, class U2>
      pair& operator=(pair<U1, U2>&& p);
 
    void swap(pair& p) noexcept(/* see description */);
  };
}

