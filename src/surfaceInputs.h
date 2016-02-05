#ifndef SURFACEINPUTS_HEADER
#define SURFACEINPUTS_HEADER

#include <string>
#include <cmath>

class SurfaceInputs
{
public:
	SurfaceInputs();
	SurfaceInputs(int fuelModelNumber, double moistureOneHour, double moistureTenHour,
		double moistureHundredHour, double moistureLiveHerbaceous, double moistureLiveWoody,
		double midflameWindSpeed, double windDirection, double slope, double slopeAspect);

	void initializeMembers();
	void updateInput(int fuelModelNumber, double moistureOneHour, double moistureTenHour,
		double moistureHundredHour, double moistureLiveHerbaceous, double moistureLiveWoody,
		double midflameWindSpeed, double windDirection, double slope, double slopeAspect);
	void setFuelModelNumber(int fuelModelNumber);
	void setMoistureDead(double moistureOneHour, double moistureTenHour, double moistureHundredHour);
	void setMoistureLive(double moistureLiveHerbaceous, double moistureLiveWoody);
	void setMoistureOneHour(double moistureOneHour);
	void setMoistureTenHour(double moistureTenHour);
	void setMoistureHundredHour(double moistureHundredHour);
	void setMoistureLiveHerbaceous(double moistureLiveHerbaceous);
	void setMoistureLiveWoody(double moistureLiveWoody);
	void setSlope(double slope);
	void setSlopeAspect(double slopeAspect);
	void setSlopeInputMode(int mode);  // slope in percent == 0, slope in degrees == 1
	void setMidflameWindSpeed(double midflameWindSpeed);
	void setWindDirection(double windDirection);
	void setWindAndSpreadDirectionMode(int mode); // From upslope == 0, From north == 1
	void setFirstFuelModelNumber(int firstFuelModelNumber);
	void setSecondFuelModelNumber(int secondFuelModelNumber);
	
	int getFuelModelNumber() const;
	double getMoistureDeadAtIndex(int index) const;
	double getMoistureLiveAtIndex(int index) const;
	double getSlope() const;
	double getSlopeAspect() const;
	double getWindDirection() const;
	double getMidflameWindSpeed() const;
	double getMoistureOneHour() const;
	double getMoistureTenHour() const;
	double getMoistureHundredHour() const;
	double getMoistureLiveHerbaceous() const;
	double getMoistureLiveWoody() const;
	bool isWindAndSpreadAngleRelativeToNorth() const;
	bool isWindAndSpreadAngleRelativeToUpslope() const;
	bool isSlopeInDegrees() const;
	bool isSlopeInPercent() const;

private:
	double convertWindToUpslope(double windDirectionFromNorth);
	void setMoistureDead();
	void setMoistureLive();

	static const int MAX_SIZES = 4;		// Max number of fuel size classes
	int		fuelModelNumber_;			// 1 to 256
	int		firstFuelModelNumber_;		// 1 to 256, first fuel used in Two Fuel Models
	int		secondFuelModelNumber_;		// 1 to 256, second fuel used in Two Fuel Models
	double	moistureOneHour_;			// 1% to 60%
	double	moistureTenHour_;			// 1% to 60%		
	double	moistureHundredHour_;		// 1% to 60%
	double	moistureLiveHerbaceous_;	// 30% to 300%
	double	moistureLiveWoody_;			// 30% to 300%
	double	midflameWindSpeed_;			// in miles per hour
	double	windDirection_;				// degrees, 0-360
	double	slope_;						// gradient 0-600 or degrees 0-80  
	double	slopeAspect_;				// degrees, 0-360
	double	moistureDead_[MAX_SIZES];	// dead fuel moisture content
	double	moistureLive_[MAX_SIZES];	// live fuel moisture content
	double	coverage;					// percent of landscape occupied by first fuel in Two Fuel Models

	enum WindAndSpreadDirectionEnumType
	{
		RELATIVE_TO_UPSLOPE = 0,	// Wind and spread direction I/O are clockwise relative to upslope
		RELATIVE_TO_NORTH = 1		// Wind direction direction I/O are clockwise relative to compass north
	};

	enum SlopeInputModeEnumType
	{
		SLOPE_IN_PERCENT = 0,	// Slope is input as a percent
		SLOPE_IN_DEGREES = 1	// Slope is input as degrees
	};

	enum TwoFuelModelsMethod
	{
		ARITHMETIC = 0,			// Use arithmetic mean
		HARMONIC = 1,			// Use harmoic mean
		TWO_DIMENSIONAL = 2,	// Use Finney's two dimensional method
	};

	WindAndSpreadDirectionEnumType windAndSpreadAngleMode_; // Determines how wind and spread directions are referenced
	SlopeInputModeEnumType slopeInputMode_;	// Determines whether slope is input as percent or degrees

};

#endif // SURFACEINPUTS_HEADER