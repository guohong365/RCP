#pragma once
#include <string>
namespace rcp {
	class IQuotation
	{
	public:
		virtual ~IQuotation() = default;
		///合约代码
		virtual const std::string& instrumentId() const= 0;
		///交易日
		virtual const std::string&tradingDay() const = 0;
		///交易所代码
		virtual const std::string&exchangeId()  const = 0;
		///合约在交易所的代码
		virtual const std::string& exchangeInstrumentId()  const = 0;
		///最新价
		virtual double lastPrice() const = 0;
		///上次结算价
		virtual double prevSettlementPrice() const = 0;
		///昨收盘
		virtual double	prevClosePrice()  const = 0;
		///昨持仓量
		virtual double	prevOpenInterest()  const = 0;
		///今开盘
		virtual double	openPrice()  const = 0;
		///最高价
		virtual double	highestPrice()  const = 0;
		///最低价
		virtual double	lowestPrice()  const = 0;
		///数量
		virtual int	volume()  const = 0;
		///成交金额
		virtual double	turnover()  const = 0;
		///持仓量
		virtual double	openInterest()  const = 0;
		///今收盘
		virtual double	closePrice()  const = 0;
		///本次结算价
		virtual double	settlementPrice()  const = 0;
		///涨停板价
		virtual double	upperLimitPrice()  const = 0;
		///跌停板价
		virtual double	lowerLimitPrice()  const = 0;
		///昨虚实度
		virtual double	prevDelta()  const = 0;
		///今虚实度
		virtual double currentDelta()  const = 0;
		///最后修改时间
		virtual const std::string&	updateTime() const = 0;
		///最后修改毫秒
		virtual int	updateMillisecond()  const = 0;
		///申买价一
		virtual double	bidPrice1()  const = 0;
		///申买量一
		virtual int	bidVolume1()  const = 0;
		///申卖价一
		virtual double	askPrice1()  const = 0;
		///申卖量一
		virtual int	askVolume1()  const = 0;
		///申买价二
		virtual double	bidPrice2()  const = 0;
		///申买量二
		virtual int	bidVolume2()  const = 0;
		///申卖价二
		virtual double	askPrice2()  const = 0;
		///申卖量二
		virtual int	askVolume2()  const = 0;
		///申买价三
		virtual double	bidPrice3()  const = 0;
		///申买量三
		virtual int	bidVolume3()  const = 0;
		///申卖价三
		virtual double	askPrice3()  const = 0;
		///申卖量三
		virtual int	askVolume3()  const = 0;
		///申买价四
		virtual double	bidPrice4()  const = 0;
		///申买量四
		virtual int	bidVolume4() const = 0;
		///申卖价四
		virtual double	askPrice4() const = 0;
		///申卖量四
		virtual int	askVolume4()  const = 0;
		///申买价五
		virtual double	bidPrice5()  const = 0;
		///申买量五
		virtual int	bidVolume5()  const = 0;
		///申卖价五
		virtual double	askPrice5() const = 0;
		///申卖量五
		virtual int	askVolume5() const = 0;
		///当日均价
		virtual double	averagePrice() const = 0;
		///业务日期
		virtual const std::string& actionDay() const = 0;

		virtual const std::string toJsonString() const = 0;
		virtual void fromJsonString(const std::string & jsonString)=0;
		static void dump(std::ostream & stream, IQuotation * p);
	};

	class AbstractQuotation : public IQuotation
	{
	public:

		~AbstractQuotation() override;

		const std::string& instrumentId() const override;

		const std::string& tradingDay() const override;

		const std::string& exchangeId() const override;

		const std::string& exchangeInstrumentId()  const override;

		double lastPrice() const override;

		double prevSettlementPrice()  const override;

		double prevClosePrice() const override;

		double prevOpenInterest() const override;

		double openPrice() const override;

		double highestPrice() const override;

		double lowestPrice() const override;

		int volume() const override;

		double turnover() const override;

		double openInterest()  const override;

		double closePrice() const override;

		double settlementPrice() const override;

		double upperLimitPrice() const override;

		double lowerLimitPrice() const override;

		double prevDelta() const override;

		double currentDelta() const override;

		const std::string& updateTime() const override;

		int updateMillisecond() const override;

		double bidPrice1() const override;

		int bidVolume1() const override;

		double askPrice1() const override;

		int askVolume1() const override;

		double bidPrice2() const override;

		int bidVolume2() const override;

		double askPrice2() const override;

		int askVolume2() const override;

		double bidPrice3() const override;

		int bidVolume3() const override;

		double askPrice3() const override;

		int askVolume3() const override;

		double bidPrice4() const override;

		int bidVolume4() const override;

		double askPrice4() const override;

		int askVolume4() const override;

		double bidPrice5() const override;

		int bidVolume5() const override;

		double askPrice5() const override;

		int askVolume5() const override;

		double averagePrice() const override;

		const std::string& actionDay() const override;

		const std::string toJsonString() const override;
		void fromJsonString(const std::string& jsonString) override;
	protected:
		AbstractQuotation(const std::string& instrumentId, const std::string& tradingDay, const std::string& exchangeId,
			const std::string& exchangeInstrumentId, const double lastPrice, const double prevSettlementPrice,
			const double prevClosePrice, const double prevOpenInterest, const double openPrice,
			const double highestPrice,
			const double lowestPrice, const int volume, const double turnover, const double openInterest,
			const double closePrice, const double settlementPrice, const double upperLimitPrice,
			const double lowerLimitPrice, const double prevDelta, const double currentDelta,
			const std::string& updateTime,
			const int updateMillisecond, const double bidPrice1, const int bidVolume1, const double askPrice1,
			const int askVolume1, const double bidPrice2, const int bidVolume2, const double askPrice2,
			const int askVolume2, const double bidPrice3, const int bidVolume3, const double askPrice3,
			const int askVolume3, const double bidPrice4, const int bidVolume4, const double askPrice4,
			const int askVolume4, const double bidPrice5, const int bidVolume5, const double askPrice5,
			const int askVolume5, const double averagePrice, const std::string& actionDay);
		AbstractQuotation();

		void instrumentId(const std::string& value);

		void tradingDay(const std::string& value);

		void exchangeId(const std::string& value);

		void exchangeInstrumentId(const std::string& value);

		void lastPrice(double value);

		void prevSettlementPrice(double value);

		void prevClosePrice(double value);

		void prevOpenInterest(double value);

		void openPrice(double value);

		void highestPrice(double value);

		void lowestPrice(double value);

		void volume(int value);

		void turnover(double value);

		void openInterest(double value);

		void closePrice(double value);

		void settlementPrice(double value);

		void upperLimitPrice(double value);

		void lowerLimitPrice(double value);

		void prevDelta(double value);

		void currentDelta(double value);

		void updateTime(const std::string& value);

		void updateMillisecond(int value);

		void bidPrice1(double value);

		void bidVolume1(int value);

		void askPrice1(double value);

		void askVolume1(int value);

		void bidPrice2(double value);

		void bidVolume2(int value);

		void askPrice2(double value);

		void askVolume2(int value);

		void bidPrice3(double value);

		void bidVolume3(int value);

		void askPrice3(double value);

		void askVolume3(int value);

		void bidPrice4(double value);

		void bidVolume4(int value);

		void askPrice4(double value);

		void askVolume4(int value);

		void bidPrice5(double value);

		void bidVolume5(int value);

		void askPrice5(double value);

		void askVolume5(int value);

		void averagePrice(double value);

		void actionDay(const std::string& value);
	private:
		std::string _instrumentId;
		std::string _tradingDay;
		std::string _exchangeId;
		std::string _exchangeInstrumentId;
		double _lastPrice;
		double _prevSettlementPrice;
		double _prevClosePrice;
		double _prevOpenInterest;
		double _openPrice;
		double _highestPrice;
		double _lowestPrice;
		int _volume;
		double _turnover;
		double _openInterest;
		double _closePrice;
		double _settlementPrice;
		double _upperLimitPrice;
		double _lowerLimitPrice;
		double _prevDelta;
		double _currentDelta;
		std::string _updateTime;
		int _updateMillisecond;
		double _bidPrice1;
		int _bidVolume1;
		double _askPrice1;
		int _askVolume1;
		double _bidPrice2;
		int _bidVolume2;
		double _askPrice2;
		int _askVolume2;
		double _bidPrice3;
		int _bidVolume3;
		double _askPrice3;
		int _askVolume3;
		double _bidPrice4;
		int _bidVolume4;
		double _askPrice4;
		int _askVolume4;
		double _bidPrice5;
		int _bidVolume5;
		double _askPrice5;
		int _askVolume5;
		double _averagePrice;
		std::string _actionDay;
	};

}